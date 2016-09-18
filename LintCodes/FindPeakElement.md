---
title: Find Peak Element
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Find Peak Element

There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

```cpp
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int l = 1, r = A.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;
            if (A[mid] > A[mid-1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

};

```
