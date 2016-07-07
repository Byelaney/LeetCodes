---
title: levenshtein
date: 2016-06-14 18:34:29
categories: algorithm
tags: DP
---

## 什么是 Levenshtein Distance?

Levenshtein distance (LD) 是一种检测字符串相似度的方法, 假设我们有字符串 s 和字符串 t, 这个距离就是字符串 s 转换到字符串 t 的步骤数,包括删除,增加和替换。比如说：

> * 如果 s 是 "test" 并且 t 是 "test",那么 LD(s,t) = 0,因为显然这两个字符串相同。
> * 如果 s 是 "test" 并且 t 是 "tent", 那么 LD(s,t) = 1, 因为只需要替换一个字母即可。

显然 LD 越大，说明两个字符串的差别越大。Levenshtein distance 是一个俄罗斯科学家发明的,他叫 Vladimir Levenshtein,自古毛子多开挂啊！这个算法的应用还是非常广泛的,比较熟悉的可能就是论文查重了。

> * 拼写的检测
> * 演讲识别
> * DNA 的分析
> * 查重方面

首先来对这个算法有一个大概的了解:

```python
# Slow, recursive Levenshtein implementation
# (inspired by <http://en.wikipedia.org/wiki/Levenshtein_distance>)
def leven(s, t):

    # base case: empty strings
    if len(s) == 0:
        return len(t)  # cost of inserting all of t
    if len(t) == 0:
        return len(s)  # cost of inserting all of s

    # test if last characters match
    if s[-1] == t[-1]:
        cost = 0    # match; no cost
    else:
        cost = 1   # no match; cost of substituting one letter.

    # return minimum of
    # - (1) delete char from s,
    # - (2) delete char from t, and
    # - (3) delete char from both
    return min(
        leven(s[:-1], t) + 1, # e.g., leven(fas, cats) + 1 (for deleting 't' from 'fast')
        leven(s, t[:-1]) + 1, # e.g., leven(fast, cat) + 1 (for deleting 's' from 'cats')
        leven(s[:-1], t[:-1]) +
          cost # e.g., leven(fas, cat) + cost (for 's'-> t)
    )
```

这里算法本身还是比较好理解的,代码的注释有很详细的说明。需要注意的是这里使用了递归,显然这很方便理解,但是如果你仔细想一下,这样的递归效率是非常低下的。道理与斐波那契数列的递归一样,重复计算了很多次我们已经计算过的项。所以我们要转变一下想法,从递归向 dynamic programming 进发。

其实 dynamic programming 还是比较容易理解的,区别就在于前面的结果和当前的结果的联系,我们每次计算都会保存好这些结果,以供之后的计算使用,具体算法如下:

| **Step**        | **Description** |
| --------   | :-----: |
| (1)        | 设 s 的长度为 n|
|          | 设 t 的长度为 m|
|          | 如果 s 的长度为0,那么就返回 m      |
|          |  如果 t 的长度为0,那么就返回 n     |
|          |  构建一个 (m+1)*(n+1) 的矩阵 dp   |
| (2)      |  把第一行的值依次设置为0到n        |
|          |   把第一列的值依次设置为0到m       |
| (3)      |   迭代 s 的每个字符(i 从 1 到 n):  |
|          |   迭代 t 的每个字符(j 从 1 到 m):  |
| (4)      |   if s[i] = t[j],那么 cost = 0     |
|          |   if s[i] != t[j],那么 cost = 1    |
| (5)      |   把 dp[i,j] 设置为以下值之中的最小值     |
|          |    (a). dp[i-1,j] + 1   |
|          |    (b). dp[i,j-1] + 1   |
|          |    (c). dp[i-1,j-1] + cost |
| (6)      |    最后,你可以在 dp[m,n] 发现最终的结果   |

第(5)步的三步可能比较难理解,其实也很简单,就是上面递归实现的三种情况。顺便提一下,时间复杂度是O(m*n)。
