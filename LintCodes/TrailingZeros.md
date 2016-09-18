---
title: Trailing Zeros
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Trailing Zeros

Write an algorithm which computes the number of trailing zeros in n factorial.

```cpp
class Solution {
 public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
    long long sum = 0;
    while (n != 0) {
        sum += n / 5;
        n /= 5;
    }
    return sum;
}
};

```
