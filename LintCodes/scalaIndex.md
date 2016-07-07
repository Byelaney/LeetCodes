---
title: scalaIndex
date: 2016-06-15 18:18:24
categories: IR
tags: Disk
---

## Building an index

至今为止我们讨论的都是内存中的操作,如果 document 太大了无法在内存中操作的时候,我们该怎么办呢？这时就涉及到和硬盘的数据交换了。影响效率的因素有:

> * 寻道的时间 (time to locate data in disk)
> * 传输的能力 (to copy from data into memory)
> * 数据在磁盘上是连续的还是不连续的

## Block sort-based indexing (BSBI)

这里比较直观的一个理解就是既然无法把所有 document 读入内存,那么我们就把 document 分成能读入内存的许多块(block),一块一块处理就好了。

1. 首先把 document 分为许多块
2. 对每一块:
* 处理每一个 block,获得 (word_id,doc_id) pairs
* 对这些 pairs 进行排序,并且构建 postings lists
* 把 postings lists 写入内存
3. 对这些 postings lists 进行 merge 操作

例如我们有以下两个 postings lists:
| word        | doc_id |
| --------   | :----:  |
| brutus     | d1,d3 |
| caesar        | d1,d2,d4   |
| noble        |  d5  |
| with        |  d1,d2,d3,d5  |

| word        | doc_id |
| --------   | :----:  |
| brutus     | d6,d7 |
| caesar        | d8,d9   |
| julius        |  d10  |
| killed        |  d8  |

合并之后如下:

| word        | doc_id |
| --------   | :----:  |
| brutus     | d1,d3,d6,d7 |
| caesar        | d1,d2,d4,d8,d9   |
| julius        |  d10  |
| killed        |  d8  |
| noble        |  d5  |
| with        |  d1,d2,d3,d5  |

```python
# BSBI: Create one postings list per block of documents.
from collections import defaultdict
from itertools import groupby

block1 = [(0, ["the", "dog", "jumped"]),
          (1, ["the", "cat", "jumped"])]

block2 = [(2, ["a", "dog", "ran"]),
          (3, ["the", "zebra", "jumped"])]

blocks = [block1, block2]

vocab = defaultdict(lambda: len(vocab))  # auto-increment word indices

for block_id, block in enumerate(blocks):
    # A. Collect all individual postings: (word_id, doc_id) pairs.
    postings = []
    for doc_id, doc in block:
        for word in doc:
            postings.append((vocab[word], doc_id))
    print('\n\nblock', block_id, 'postings=', postings)
    print('\nvocab=', vocab.items())

    # B. Sort postings and create postings lists.
    postings = sorted(postings)  # sorts by first element of tuple by default
    print('\nblock', block_id, 'sorted postings=', postings)

    # Group postings for same term together.
    postings = groupby(postings, key=lambda x:x[0])
    postings = [(word_id, [g[1] for g in group]) for word_id, group in postings]
    print('\nblock', block_id, 'grouped postings=', postings)

    # C. Write to disk
    f = open('bsbi_block' + str(block_id) + '.txt', 'wt')
    f.write('\n'.join(['%s' % str(p) for p in postings]))
    f.close()
    print

# Then, merge blocks in linear time.
```

## Single-pass in-memory indexing (SPIMI)

1. separate dictionary for each block
2. create postings lists on the fly, rather than collecting all postings then sorting.
3. sort postings lists, rather than individual postings

```python
# SPIMI: Create one postings list per block of documents.
from collections import defaultdict
from itertools import groupby

block1 = [(0, ["the", "dog", "jumped"]),
          (1, ["the", "cat", "jumped"])]

block2 = [(2, ["a", "dog", "ran"]),
          (3, ["the", "zebra", "jumped"])]

blocks = [block1, block2]

for block_id, block in enumerate(blocks):
    # Note that there is a new vocab for each block!
    vocab = defaultdict(lambda: len(vocab))  # maps from term -> term_id
    index = defaultdict(lambda: [])          # from term_id -> postings list

    for doc_id, doc in block:
        # append doc_id to the postings list of each term
        for word in doc:
            index[vocab[word]].append(doc_id)


    # B. Sort terms
    sorted_terms = sorted(vocab.keys())
    print('\n\nBlock', block_id, [t + ' ' + str(index[vocab[t]]) for t in sorted_terms])

    # C. Write to disk
    f = open('spimi_block' + str(block_id) + '.txt', 'wt')
    f.write('\n'.join(['%d, %s' %
                      (vocab[t], str(index[vocab[t]]))
                      for t in sorted_terms]))
    f.close()
    print
    print('\n\t', vocab.items())
```

## MapReduce

下来大致介绍一下大名鼎鼎的 MapReduce,如果我们现在有10万台服务器的话,我们能如何利用它们呢？

1. MapReduce 是一种分布式的编程框架。
2. 把巨大的数据分为小的数据,这一步称为 splits

主要有两个阶段:

1. Map:
* Input:one split
* Output:(key,value) pairs
2. Reduce:
* Input:(key,list of mapped values)
* Output:list of output values

## Indexing with MapReduce

> Map: Read a document and output (term, doc_id) pairs.
> Reduce: Read a list of doc_ids for a term and output a postings list.

### Mapper

"Twinkle, twinkle little star" → Mapper 1 → (twinkle, 0), (little, 0), (star, 0)
"Little by little" → Mapper 2 → (little, 1), (by, 1)

### Reduce
(little, 0), (little, 1) → Reducer 1 → (little, [0, 1])
