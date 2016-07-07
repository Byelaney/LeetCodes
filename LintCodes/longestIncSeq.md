---
title: longestIncSeq
date: 2016-06-15 22:45:43
categories: LintCode
tags: Pointers
---

## 最长上升连续子序列

给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。（最长上升连续子序列可以定义为从右到左或从左到右的序列。）

根据题意这题好像挺难的样子,标签上说要用枚举法或者动态数组。但我其实觉得还可以,从左往右扫描,相邻的数字进行比大小,这里关键就是比了大小之后,你可以进行一系列操作,等于另一序列在同时进行。

```cpp
int longestIncreasingContinuousSubsequence(vector<int>& A) {
    // Write your code here
    if (A.size() == 0) return 0;
    int p1 = 0;
    int max = 0;
    int max1 = 0; //ascending max
    int max2 = 0; //descending max
    int counter = 0;
    while (counter < A.size())
    {
        if (p1 < A.size()-1 && A[p1] < A[p1+1])
        {
            max2 = 0;
            ++max1;
            if (max1 > max)
                max = max1;
        }
        else if (p1 < A.size()-1 && A[p1] >= A[p1+1])
        {
            max1 = 0;
            ++max2;
            if (max2 > max)
                max = max2;
        }
        else
        {
            //do nothing
        }
        ++counter;++p1;
    }
    return max+1;
}
```
