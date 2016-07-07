---
title: setZeroMatrix
date: 2016-07-06 15:31:49
categories: LintCode
tags: Matrix
---

## 矩阵归零

给定一个m×n矩阵，如果一个元素是0，则将其所在行和列全部元素变成0。需要在原矩阵上完成操作。

这题最优解法我没有想出来，看了答案终于懂了。原来是利用了第一行和第一列来存储[i,j]是否为0这个信息。最关键的一点就是，如果[i,j]是0的话，那么对应的[0,j] 和[i,0]肯定都是0，我们只要知道哪一行哪一列有0就可以了。

```cpp
void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) return;
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();

    bool zero_row = false;
    bool zero_col = false;

    for(int i = 0;i<col;++i)
        if (matrix[0][i] == 0)
        {
            zero_row = true;
            break;
        }

    for(int i = 0;i<row;++i)
        if (matrix[i][0] == 0)
        {
            zero_col = true;
            break;
        }

    for(int i = 1;i<row;++i)
    {
        for(int j = 1;j<col;++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i = 1;i<row;++i)
    {
        for(int j = 1;j<col;++j)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    if (zero_row)
        for(int i = 0;i<col;++i)
            matrix[0][i] = 0;
    if (zero_col)
        for(int i = 0;i<row;++i)
            matrix[i][0] = 0;
}
```
