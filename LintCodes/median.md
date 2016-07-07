---
title: median
date: 2016-06-16 20:32:08
categories: LintCode
tags: PriorityQueue
---

## 中位数

给定一个未排序的整数数组，找到其中位数。中位数是排序后数组的中间值，如果数组的个数是偶数个，则返回排序后数组的第N/2个数。

这题其实还挺难的,当然你可以先排序然后再直接取中间那个数,这里考虑一种不一样的解法,使用 Priority Queue。假设数组长度是奇数 N,那么我们要做的就是找到一个数,这个数满足什么条件呢？只要有 (N-1)/2 个数比它小(或等于),(N-1)/2 个数比它大(或等于)就可以了。为什么要使用 Priority Queue呢,因为很容易获取到 queue 里最大的那个数,我们要做的就是先往 queue 里塞数,直到它的长度到了 (N-1)/2,之后再把剩下的数和 queue 的 top(最大的数) 比较即可。代码如下:

```cpp
int median(vector<int> &nums) {
        int k = (nums.size() + 1) / 2;
        priority_queue<int> que;
        int len = nums.size();
        for(int i = 0; i < len; i ++) {
            if(que.size() == k) {
                if(nums[i] < que.top()) {
                    que.pop();
                    que.push(nums[i]);
                }
            }else {
                que.push(nums[i]);
            }
        }
        return que.top();
    }
```
