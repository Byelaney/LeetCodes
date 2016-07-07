---
title: findMissing
date: 2016-07-03 23:12:16
categories: LintCode
tags: accessing
---

## 寻找缺失的数

给出一个包含 0 .. N 中 N 个数的序列，找出0 .. N 中没有出现在序列中的那个数。可以改变序列中数的位置。
N = 4 且序列为 [0, 1, 3] 时，缺失的数为2。

这题我竟然自己想出来了，不过写的很丑陋罢了。我是这样想的，由于有 N 个数，并且是 0 ～ N，正好对应了数组的下标。如果有一种办法，让每个数 nums[i] 都对应了它的下标，即 nums[i] = i。那么当我们一遍遍历的时候，不等的那个就是缺失的数。现在问题就是怎么去交换了，一开始我的想法是遍历一个换一个，但结果这样是行不通的。于是我想了另一个办法，把 nums[i] 当成指针，直到 nums[i] = i 就停止即可。想通了这些，代码就很简单了。

```cpp
int findMissing(vector<int> &nums) {
    for(int i = 0;i<nums.size();++i)
    {
        if (nums[i] >= nums.size())
            continue;
        else
        {
            if (nums[i] == i) continue;
            else
            {
                int next = nums[i];
                while (1)
                {
                    swap(nums[i], nums[next]);
                    next = nums[i];
                    if (nums[i] == i || nums[i] >= nums.size())
                        break;
                }
            }
        }
    }
    for(int i = 0;i<nums.size();++i)
        if (nums[i] != i)
            return i;

    return (int)nums.size();
}
```

我写的比较长比较丑陋，我后来参考了一下答案，思路是一样的，但是答案非常简洁，然后答案的时间在 195ms 左右，我的在140ms 左右，可能是测试数据的问题把。。。

```cpp
int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size(), i = 0;
        while (i<n) {
            while (nums[i]!=i && nums[i]<n) swap(nums[i], nums[nums[i]]);  
            ++i;
        }
        for (int i=0; i<n; ++i)
            if (nums[i]!=i) return i;
        return n;
    }
```
