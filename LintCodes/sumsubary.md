---
title: sumsubary
date: 2016-06-21 22:50:14
categories: LintCode
tags: SubArray
---

## 子数组之和

给定一个整数数组，找到和为零的子数组。你的代码应该返回满足要求的子数组的起始位置和结束位置。

真是遗憾，这是第二道我没想出来的题目，我怎么这么笨啊。。。答案把 sum 当作了 map 的 key 进而进行比较，真是太厉害了。

```cpp
vector<int> subarraySum(vector<int> nums){
    // write your code here
    unordered_map<int, int> um;
    um[0] = -1;
    vector<int> v;
    int sum = 0;
    for(int i = 0;i<nums.size();++i)
    {
        sum += nums[i];
        if (um.count(sum) > 0)
        {
            v.push_back(um[sum]+1);
            v.push_back(i);
            return v;
        }
        um[sum] = i;
    }
    return v;
}
```
