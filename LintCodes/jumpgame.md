---
title: jumpgame
date: 2016-06-26 23:10:37
categories: LintCode
tags: greedy
---

## 跳跃游戏

给出一个非负整数数组，你最初定位在数组的第一个位置。数组中的每个元素代表你在那个位置可以跳跃的最大长度。判断你是否能到达数组的最后一个位置。

这个问题有两个方法，一个是贪心和 动态规划。贪心方法时间复杂度为O（N）。动态规划方法的时间复杂度为为O（n^2）。我们手动设置小型数据集，使大家阔以通过测试的两种方式。这仅仅是为了让大家学会如何使用动态规划的方式解决此问题。如果您用动态规划的方式完成它，你可以尝试贪心法，以使其再次通过一次。

这题我的思路是随便想的，我也不知道对不对。实际上我们的难点在于选择下一步应该跳到哪里，我的思路是，跳到离终点最近的那个点。方法就是遍历当前点能到达的所有点，计算出那个点所能达到的新的点，然后选出最远的那个点。

```cpp
int nextMove(vector<int> A,vector<int> v)
{
    int max = -1;
    int id = -1;
    for(int i = 0;i<v.size();++i)
    {
        if (v[i] < A.size())
        {
            int next = v[i] + A[v[i]];
            if (next >= max)
            {
                max = next;
                id = v[i];
            }
        }
    }
    return id;
}


bool canJump(vector<int> A) {
    if (A.size() == 0) return true;

    int i = 0;
    int last_i = 0;
    while (i != A.size()-1)
    {
        vector<int> v;
        for(int j = 1;j<=A[i];++j)
        {
            v.push_back(i+j);
        }
        int next = nextMove(A, v);
        if (next < 0)
            return false;

        last_i = i;
        i = next;
        if (last_i == i && i < A.size()-1)
            return false;
    }

    return true;
}
```
