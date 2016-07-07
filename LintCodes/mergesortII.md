---
title: mergesortII
date: 2016-06-22 10:08:58
categories: LintCode
tags: Merge
---

## 合并排序数组 II

合并两个排序的整数数组A和B变成一个新的数组。

给出 A = [1, 2, 3, empty, empty], B = [4, 5],合并之后 A 将变成 [1,2,3,4,5]。

这题要转变思路,从后往前来合并,注意 B 数组可能没有合并完。

```cpp
void mergeSortedArray(int A[], int m, int B[], int n) {
    int p1 = m-1;
    int p2 = n-1;
    int p3 = m + n -1;

    while (p1 >= 0 && p2 >= 0)
    {
        if (A[p1] <= B[p2])
        {
            A[p3] = B[p2];
            --p2;
        }
        else
        {
            A[p3] = A[p1];
            --p1;
        }
        --p3;
    }
    while (p3 >= 0 && p2 >= 0)
        A[p3--] = B[p2--];
}
```
