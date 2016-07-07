---
title: bst2
date: 2016-06-08 10:17:11
categories: LintCode
tags: [greedy]
mathjax: true
---

## 买卖股票的最佳时机 II

假设有一个数组，它的第i个元素是一个给定的股票在第i天的价格。设计一个算法来找到最大的利润。你可以完成尽可能多的交易(多次买卖股票)。然而,你不能同时参与多个交易(你必须在再次购买前出售股票)。

对我来说，这题有点类似连续和最大那道题，其实题目的关键是 **什么时候该买**，**什么时候该卖**。我的想法是每次遇到一个价格，如果手里没有股票的话就先买下来。如果遇到比当前手里股票便宜的股票，就用低价的股票来替代当前手里的股票。确定买的时机比较简单，难的是确定什么时候该卖，这里就不同于连续和最大了，没有连续的要求(可以仔细体会一下)。现在我们手里握有股票 **buy**,看到了今天的股票价格 **P_i**,首先要保证 **P_i - buy > 0**,但这并不一定使利润最大化，最关键的一个条件就是 **P_{i+1} < P_i**,也就是明天的股票没有今天值钱了，这时候我们才可以确定地去售出。

```cpp
int maxProfit(vector<int> &prices) {
    // write your code here
    int buy = -1;
    int profit = 0;

    for (int i = 0;i<prices.size();++i)
    {
        if (buy == -1)
        {
            // we need to buy first
            buy = prices[i];
        }
        else
        {
            if (prices[i] < buy)
                buy = prices[i];
            else
            {
                if (i+1 < prices.size())
                {
                    if(prices[i+1] < prices[i])
                    {
                        profit += prices[i] - buy;
                        buy = -1;
                    }
                }
                else
                {
                    profit += prices[i] - buy;
                    buy = -1;
                }
            }
        }
    }
    return profit;
}
```
