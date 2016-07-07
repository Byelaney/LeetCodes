---
title: paintroof
date: 2016-07-01 10:41:35
categories: LintCode
tags: DP
---

## 房屋染色

这里有n个房子在一列直线上，现在我们需要给房屋染色，分别有红色蓝色和绿色。每个房屋染不同的颜色费用也不同，你需要设计一种染色方案使得相邻的房屋颜色不同，并且费用最小。费用通过一个 nx3 的矩阵给出，比如cost[0][0]表示房屋0染红色的费用，cost[1][2]表示房屋1染绿色的费用。

costs = [[14,2,11],[11,14,5],[14,3,10]] return 10

这题是典型的动态规划问题，我的理解是这样的。想要知道当前最小的 cost c_i，由于只有三个颜色方案，所以当前的选择的颜色只有3个可能(红蓝绿)。如果当前选的是红色，那么上一个选的只能是蓝色或者是绿色，其余的也同理。所以在决定当前最小的 cost c_i 的时候，总共有 3*2 = 6 个方案。如果我们能求出这六个方案，那么只要从这六个里面选出来值最小的就行了。所以我们每次需要记录三个值，即当前颜色的最小值。首先设置初始值，就是第一个房子三个颜色的最小值。之后从第二个房子开始，每次都利用上一次的结果，最后就能得到最终的最小值了。

```cpp
int minCost(vector<vector<int>>& costs) {
    if (costs.size() == 0) return 0;
    vector<int> start = costs[0];
    vector<vector<int>> dp;
    dp.push_back(start);
    for(int i = 1;i<costs.size();++i)
    {
        vector<int> d;
        int red = min(costs[i][0] + dp[i-1][1], costs[i][0] + dp[i-1][2]);
        int blue = min(costs[i][1] + dp[i-1][0], costs[i][1] + dp[i-1][2]);
        int green = min(costs[i][2] + dp[i-1][0], costs[i][2] + dp[i-1][1]);
        d.push_back(red);
        d.push_back(blue);
        d.push_back(green);
        dp.push_back(d);
    }
    vector<int> final = dp[costs.size()-1];
    int cost1 = min(final[0], final[1]);
    return min(cost1,final[2]);
}
```
