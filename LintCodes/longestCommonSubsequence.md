---
title: longestCommonSubsequence
date: 2016-07-12 09:05:45
categories: LintCode
tags: DP
---

## 最长公共子序列

给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度。

最长公共子序列的定义：

最长公共子序列问题是在一组序列（通常2个）中找到最长公共子序列（注意：不同于子串，LCS不需要是连续的子串）。该问题是典型的计算机科学问题，是文件差异比较程序的基础，在生物信息学中也有所应用。

不会做啊，看了答案的。关键是先比较最后一个字符是否相同，相同的话就转化为 m-1 和 n-1 的最长公共子序列加1，不同的话就取 max([m-1,n],[m,n-1])。具体实现就是用动态规划了。

```cpp
int longestCommonSubsequence(string A, string B) {
    if (A.size() == 0 || B.size() == 0) return 0;
    
    int dp[A.size()][B.size()];
    for(int i = 0;i<B.size();++i)
    {
        if (A[0] == B[i])
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for(int i = 0;i<A.size();++i)
    {
        if (A[i] == B[0])
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }

    for (int row = 1; row < A.size(); ++row) {
        for(int col = 1;col < B.size();++col)
        {
            if (A[row] == B[col])
            {
                dp[row][col] = 1 + dp[row-1][col-1];
            }
            else
            {
                dp[row][col] = max(dp[row-1][col],dp[row][col-1]);
            }
        }
    }

    return dp[A.size()-1][B.size()-1];
}
```
