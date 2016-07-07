---
title: levenshtein2
date: 2016-06-15 09:41:07
categories: algorithm
tags: application
---

##  Levenshtein Distance 的延伸

上一篇介绍了具体怎么算 Levenshtein Distance,这一篇我来大概讲讲应用。

例如当你要处理拼写错误的时候,你就可以利用这个 Levenshtein Distance,具体怎么用呢？一个很容易想到的方法就是搜索你的词语库,计算输入和词语库词语的 Levenshtein Distance,返回值最小的那个是比较合理的。这个方法乍一看很美,其实是不太现实的,因为词语库一般都很大,而处理拼写错误的请求是很频繁的,这样的计算代价太大了,或者说效率很低。那么有没有什么好办法呢？答案是肯定的。这里要提到一个词 'trade off',我们需要牺牲一定的准确性。我们可以反过来思考,现在我们有了用户输入的 term ,并且根据以往的统计经验,70%-80%的拼写错误都是一个字符的错误,于是我们可以利用这一点,生成所有可能的字符串。

```python
alphabet = 'abcdefghijklmnopqrstuvwxyz'
def edits(word, verbose=False):
    """ Return all single edits to word.
    Consider insertions, deletes, replacement, and transposition.
    """
    splits     = [(word[:i], word[i:]) for i in range(len(word) + 1)]
    # e.g., cat -> [('', 'cat'), ('c', 'at'), ('ca', 't'), ('cat', '')]
    deletes    = [a + b[1:] for a, b in splits if b]                       # cat-> ca
    transposes = [a + b[1] + b[0] + b[2:] for a, b in splits if len(b)>1]  # cat -> act
    replaces   = [a + c + b[1:] for a, b in splits for c in alphabet if b] # cat -> car
    inserts    = [a + c + b     for a, b in splits for c in alphabet]      # cat -> cats
    if verbose:
        print('splits=%s\ndeletes=%s\ntransposes=%s\nreplaces=%s\ninserts=%s\n' %
             (splits, deletes, transposes, replaces, inserts))
    return set(deletes + transposes + replaces + inserts)                  # union all edits
    # n deletions, n-1 transpositions, 26n substitutions, and 26(n+1) insertions, for a total of 54n+25.
```


## 如何使用 spelling correction?
> * Make suggestions ("Did you mean?")
> * Add corrected terms to query
> * only if query term is not in dictionary
> * only if number of matches < N
