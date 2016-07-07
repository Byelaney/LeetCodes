---
title: bst1
date: 2016-06-08 16:39:22
categories: LintCode
tags: DP
---

## 买卖股票的最佳时机

假设有一个数组，它的第i个元素是一支给定的股票在第i天的价格。如果你最多只允许完成一次交易(例如,一次买卖股票),设计一个算法来找出最大利润。

好吧...我承认我的解法很耗空间，但不知道为什么第一反应就是这样做，感觉深受 **dynamic programming** 的毒害啊。

```cpp
int maxProfit(vector<int> &prices) {
    // write your code here
    if (prices.size() == 0 || prices.size() == 1) return 0;
    vector<int> dp;
    vector<int> buy;
    dp.push_back(0);
    buy.push_back(prices[0]);
    int i;
    for(i = 1;i<prices.size();++i)
    {
        if (prices[i] - buy[i-1] > dp[i-1])
        {
            dp.push_back(prices[i] - buy[i-1]);
            buy.push_back(buy[i-1]);
        }
        else
        {
            dp.push_back(dp[i-1]);
            if (prices[i] < buy[i-1])
                buy.push_back(prices[i]);
            else
                buy.push_back(buy[i-1]);
        }
    }
    if (dp[i-1] < 0) return 0;
    return dp[i-1];
}
```
