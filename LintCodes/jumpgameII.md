---
title: jumpgameII
date: 2016-06-29 16:53:10
categories: LintCode
tags: greedy
---

## 跳跃游戏 II

给出一个非负整数数组，你最初定位在数组的第一个位置。数组中的每个元素代表你在那个位置可以跳跃的最大长度。你的目标是使用最少的跳跃次数到达数组的最后一个位置。
给出数组A = [2,3,1,1,4]，最少到达数组最后一个位置的跳跃次数是2(从数组下标0跳一步到数组下标1，然后跳3步到数组的最后一个位置，一共跳跃2次)

思路还是 greedy,参考 jumpgame 的解法。

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
        else
            return (int)A.size()-1;
    }
    return id;
}

int jump(vector<int> A) {
    if (A.size() == 0) return 0;
    int i = 0;
    int last_i = 0;
    int steps = 0;
    while (i != A.size()-1)
    {
        vector<int> v;
        for(int j = 1;j<=A[i];++j)
            v.push_back(i+j);
        int next = nextMove(A, v);
        last_i = i;
        i = next;
        ++steps;
    }
    return steps;
}
```
