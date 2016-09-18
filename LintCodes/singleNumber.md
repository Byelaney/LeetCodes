---
title: Single Number
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Single Number

Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

```cpp
class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        if (A.size() < 1) return 0;
        int lonely = A[0];
        for(int i = 1;i<A.size();++i)
        {
            lonely = lonely ^ A[i];
        }
        return lonely;
    }
};

```
