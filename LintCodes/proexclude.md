---
title: proexclude
date: 2016-06-19 23:11:25
categories: LintCode
tags: Array
---

## 数组剔除元素后的乘积

给定一个整数数组A。定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。

其实这题意义挺大的,有时候全部乘起来会溢出所以需要这样的方法。关键是使用一个辅助数组来存储乘积。

```cpp
vector<long long> productExcludeItself(vector<int> &nums) {
    // write your code here
    vector<long long> v;
    int n = (int)nums.size();
    long long aux[n+1];
    aux[n] = 1;
    for(int i = n-1;i>=0;--i)
    {
        aux[i] = aux[i+1] * nums[i];
    }
    long long tmp = 1;
    for(int i = 0;i<n;++i)
    {
        v.push_back(tmp*aux[i+1]);
        tmp *= nums[i];
    }
    return v;
}
```
