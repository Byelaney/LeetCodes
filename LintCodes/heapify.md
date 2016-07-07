---
title: heapify
date: 2016-06-27 14:20:42
categories: LintCode
tags: Heap
---

## 堆化

给出一个整数数组，堆化操作就是把它变成一个最小堆数组。对于堆数组A，A[0]是堆的根，并对于每个A[i]，A [i * 2 + 1]是A[i]的左儿子并且A[i * 2 + 2]是A[i]的右儿子。

这题考察对堆的理解，其实就是一个堆排序堆的初始化的过程。分步的思想，每一步都把父亲节点变为三个节点中最大或最小的那一个。从最后一个父亲节点开始一直到第一个父亲节点，进行这个操作即可。

```cpp
void min_heapify(vector<int> &A, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son < end)
    {
        if (son+1 < end && A[son+1] < A[son])
            ++son;
        if (A[dad] < A[son])
            break;
        else
        {
            swap(A[dad], A[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}


void heapify(vector<int> &A) {
    int len = (int)A.size();
    for(int i = len/2-1;i>=0;--i)
    {
        min_heapify(A, i, len);
    }
}
```
