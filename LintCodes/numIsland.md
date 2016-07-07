---
title: numIsland
date: 2016-06-23 22:47:46
categories: LintCode
tags: Iterate
---

## 岛屿的个数

给一个01矩阵，求不同的岛屿的个数。0代表海，1代表岛，如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。

不敢说什么东西了,我写的太难看了.....

```cpp
void contaminate(vector<vector<bool>>& grid,int row,int col,int m,int n)
{
    if (grid[row][col] == 0) return;
    grid[row][col] = 0;
    if (row == 0)
    {
        if (col == 0)
        {
            contaminate(grid, row, col+1,m,n);
            if (row < m-1)
                contaminate(grid, row+1, col,m,n);
        }
        else
        {
            if (col < n-1)
                contaminate(grid, row, col+1,m,n);
            if (row < m-1)
                contaminate(grid, row+1, col,m,n);

            contaminate(grid, row, col-1,m,n);
        }
    }
    else
    {
        if (col == 0)
        {
            if (col < n-1)
                contaminate(grid, row, col+1,m,n);
            if (row < m-1)
                contaminate(grid, row+1, col,m,n);
            contaminate(grid, row-1, col,m,n);
        }
        else
        {
            if (col < n-1)
                contaminate(grid, row, col+1,m,n);
            if (row < m-1)
                contaminate(grid, row+1, col,m,n);

            contaminate(grid, row-1, col,m,n);
            contaminate(grid, row, col-1,m,n);
        }
    }
}

int numIslands(vector<vector<bool>>& grid) {
    int m = (int)grid.size();
    if (m == 0) return 0;

    int n = (int)grid[0].size();
    int islands = 0;
    for(int i = 0;i<m;++i)
    {
        for(int j = 0;j<n;++j)
        {
            if (grid[i][j] == 1)
            {
                ++islands;
                contaminate(grid, i, j, m, n);
            }
        }
    }
    return islands;
}
```
