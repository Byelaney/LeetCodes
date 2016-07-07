---
title: interleaveMP
date: 2016-07-05 23:48:14
categories: LintCode
tags: Pointer
---

## 交错正负数

给出一个含有正整数和负整数的数组，重新排列成一个正负数交错的数组。给出数组[-1, -2, -3, 4, 5, 6]，重新排序之后，变成[-1, 5, -2, 4, -3, 6]或者其他任何满足要求的答案。

我的想法是这样的，如果数组的个数是偶数的话，那么开头和末尾的数的符号一定是不同的，哪个负哪个正无所谓。如果数组的个数是奇数的话，开头和末尾数的符号必须是一样的，而且必须是整个数组中出现更多的那个符号。只要两个指针，分别指向奇数和偶数就可以了。

```cpp
void cross(vector<int> &A,int ft)
{
    int p1 = 0;
    int p2 = 1;
    if (ft == 0)
    {
        while (p1 < A.size() && p2 < A.size())
        {
            if (A[p1] < 0)
                p1 += 2;
            else
            {
                swap(A[p1], A[p2]);
                p2 += 2;
            }
        }
    }
    else
    {
        while (p1 < A.size() && p2 < A.size())
        {
            if (A[p1] > 0)
                p1 += 2;
            else
            {
                swap(A[p1], A[p2]);
                p2 += 2;
            }
        }
    }
}

void rerange(vector<int> &A) {
    if (A.size() == 0 || A.size() == 1) return;
    if (A.size()%2 == 0)
        cross(A,0);
    else
    {
        int minus = 0;
        for(int i = 0;i<A.size();++i)
            if (A[i] < 0)
                ++minus;
        int pos = (int)A.size() - minus;
        if (pos > minus)
            cross(A,1);
        else
            cross(A,0);
    }
}
```
