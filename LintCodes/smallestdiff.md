---
title: smallestdiff
date: 2016-06-18 10:16:31
categories: LintCode
tags: vector
---

## 最小差

给定两个整数数组（第一个是数组 A，第二个是数组 B），在数组 A 中取 A[i]，数组 B 中取 B[j]，A[i] 和 B[j]两者的差越小越好(|A[i] - B[j]|)。返回最小差。

题目比较简单,先排序然后双指针比较即可。我写的花了1000ms,我以为太慢了于是去参考了一下答案。发现答案是用 set 写的,先把 A 的元素放进 set ,之后再遍历 B 的元素和 set 里的元素比较,写的比较简洁。然而时间却差不多比我的还慢了50ms...好吧 做出来就好。

```cpp
int smallestDifference(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int p1 = 0;
    int p2 = 0;
    int min = 2147483647;
    while (p1 < A.size() && p2 < B.size())
    {
        if (A[p1] < B[p2])
        {
            if (abs(A[p1]-B[p2]) < min)
                min = abs(A[p1]-B[p2]);
            ++p1;
        }
        else if (A[p1] > B[p2])
        {
            if (abs(A[p1]-B[p2]) < min)
                min = abs(A[p1]-B[p2]);
            ++p2;
        }
        else
            return 0;
    }
    return min;
}
```

```cpp
int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int diff = 0x7fffffff;
        int la = A.size();
        set<int> s;
        for (int i = 0; i < la; ++i)
               s.insert(A[i]);

        int lb = B.size();
        for (int i = 0; i < lb; ++i) {
            set<int>::iterator it = s.lower_bound(B[i]);
            if (it != s.end())
                diff = min(diff, *it - B[i]);
            if (it != s.begin()) {
                it --;
                diff = min(diff, B[i] - *it);
            }
        }
        return diff;
    }
```
