---
title: uniquepathII
date: 2016-06-22 16:10:51
categories: LintCode
tags: DP
---

## 不同的路径 II

"不同的路径" 的跟进问题：

现在考虑网格中有障碍物，那样将会有多少条不同的路径？网格中的障碍和空位置分别用 1 和 0 来表示。



```cpp
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // write your code here
    int dp[100][100];
    int m = (int)obstacleGrid.size();
    if (m > 0)
    {
        int n = (int)obstacleGrid[0].size();
        for(int i = 0;i<n;++i)
        {
            if (obstacleGrid[0][i] != 1)
                dp[0][i] = 1;
            else
            {
                dp[0][i] = 0;
                for(int j = i+1;j<n;++j)
                {
                    dp[0][j] = 0;
                }
                break;
            }
        }

        for(int i = 0;i<m;++i)
        {
            if (obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            else
            {
                dp[i][0] = 0;
                for(int j = i+1;j<m;++j)
                {
                    dp[j][0] = 0;
                }
                break;
            }

        }

        for(int i = 1;i<m;++i)
        {
            for(int j = 1;j<n;++j)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    else return 0;
}
```
