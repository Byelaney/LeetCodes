---
title: houserobber
date: 2016-07-07 14:22:47
categories: LintCode
tags: DP
---

## 打劫房屋

假设你是一个专业的窃贼，准备沿着一条街打劫房屋。每个房子都存放着特定金额的钱。你面临的唯一约束条件是：相邻的房子装着相互联系的防盗系统，且 当相邻的两个房子同一天被打劫时，该系统会自动报警。

给定一个非负整数列表，表示每个房子中存放的钱， 算一算，如果今晚去打劫，你最多可以得到多少钱 在不触动报警装置的情况下。

这题总算还是没看提示自己做出来了，我的想法是从最普通的[3,5,3]入手。当遍历到 A[i]，为了求出 dp_cur 的时候，我还同时记录了 前一个最大值 dp_prev。我们面临的问题就是要不要抢劫这个 A[i]，显然如果钱多那就抢，钱少就不抢啊。我还想要知道我对 A[i-1] 是否进行了抢劫，如果没抢，那么显然最大值是 dp_cur + A[i]。如果抢了，那么最大值就是 max(dp_prev + A[i],dp_cur)。之后只要保证 dp_cur 和 dp_prev 的更新即可。

```cpp
long long houseRobber(vector<int> A) {
    if (A.size() == 0) return 0;
    if (A.size() == 1) return A[0];
    if (A.size() == 2) return max(A[0],A[1]);

    long long dp_prev = A[0];
    long long dp_cur = 0;
    bool current = false;
    if (A[0] < A[1])
    {
        current = true;
        dp_cur = A[1];
    }
    else
        dp_cur = A[0];

    for(int i = 2;i<A.size();++i)
    {
        if (current)
        {
            if (dp_prev + A[i] > dp_cur)
            {
                long long tmp = dp_cur;
                dp_cur = dp_prev + A[i];
                dp_prev = tmp;
            }
            else
            {
                current = false;
                dp_prev = dp_cur;
            }
        }
        else
        {
            current = true;
            dp_prev = dp_cur;
            dp_cur += A[i];
        }
    }
    return dp_cur;
}
```
