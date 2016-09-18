---
title: Best Time to Buy and Sell Stock II
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Best Time to Buy and Sell Stock II

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
```cpp
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
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
};
```
