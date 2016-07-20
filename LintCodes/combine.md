---
title: combine
date: 2016-07-20 10:04:54
categories: LintCode
tags: Recursion
---

## 组合

组给出两个整数n和k，返回从1......n中选出的k个数的组合。

例如 n = 4 且 k = 2

返回的解为：

[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]

这题我还是比较顺手的，一下子就解出来了。考虑递归解法，如果已经得到了 (n,k-1) 的组合，那么我们只要遍历再添加一个新的就行了。


```cpp
vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> v;
    if (n == 0 || k == 0) return v;
    if (k == 1)
    {
        for(int i = 1;i<=n;++i)
        {
            vector<int> v1;
            v1.push_back(i);
            v.push_back(v1);
        }
        return v;
    }
    vector<vector<int>> prior = combine(n, k-1);
    for(int i = 0;i<prior.size();++i)
    {
        vector<int> v1 = prior[i];
        for(int j = v1[v1.size()-1]+1;j<=n;++j)
        {
            vector<int> v2(v1);
            v2.push_back(j);
            v.push_back(v2);
        }
    }
    return v;
}
```
