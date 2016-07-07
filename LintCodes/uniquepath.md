---
title: uniquepath
date: 2016-06-12 09:34:38
categories: LintCode
tags: DP
---

## 不同的路径

有一个机器人的位于一个M×N个网格左上角。

机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角（下图中标记为'Finish'）。
问有多少条不同的路径？ n和m均不超过100

这题一开始我是用递归做的，递推式是 **f(m,n) = f(m-1,n) + f(m,n-1)**，后来发现超时了，主要还是函数调用和反复计算了很多次之前可能已经算过的 **f(i,j)**，那就使用 **DP** 好了，递推还是一样的。

```cpp
class Solution {
public:
    int dp[100][100];
    int uniquePaths(int m, int n) {
    for(int i = 0; i < n; i++)
        dp[0][i] = 1;

    for(int i = 0; i < m; i++)
        dp[i][0] = 1;

    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
}
};
```
