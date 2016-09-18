---
title: Merge Two Sorted Arrays
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Merge Two Sorted Arrays

Merge two given sorted integer array A and B into a new sorted integer array.

```cpp
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here

    int i1 = 0;
    int i2 = 0;
    vector<int> res;

    while(i1 < A.size() && i2 < B.size())
    {
        if(A[i1] < B[i2])
        {
            res.push_back(A[i1++]);
        }
        else if(A[i1] >= B[i2])
        {
            res.push_back(B[i2++]);
        }
    }

    while(i1 < A.size())
        res.push_back(A[i1++]);

    while(i2 < B.size())
        res.push_back(B[i2++]);

    return res;
    }
};
```
