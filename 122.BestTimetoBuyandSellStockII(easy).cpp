/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int totalProfit = 0;
    for (int day=1; day<prices.size(); ++day) {
        int profit = prices[day] - prices[day-1];
        if (profit > 0)  totalProfit += profit;
    }
    return totalProfit;
}
};

/*

This problem is intriguing, if you can get profit today,just do it.
 As days go on,finally you will get the max profit.
 This may be called greedy strategy.

*/
