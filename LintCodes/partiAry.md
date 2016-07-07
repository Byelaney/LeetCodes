---
title: partiAry
date: 2016-06-12 10:21:27
categories: LintCode
tags: TwoPointer
---

## 奇偶分割数组

分割一个整数数组，使得奇数在前偶数在后。

比较简单，维护两个指针，一个从数组头部开始，另一个从数组尾部开始，向中间逼近即可。

```cpp
void partitionArray(vector<int> &nums) {
        // write your code here
    int start = 0;
    int end = (int)nums.size()-1;
    while (start < end)
    {
        if (nums[start] % 2 == 0)
        {
            if (nums[end] %2 == 1)
            {
                int tmp = nums[start];
                nums[start] = nums[end];
                nums[end] = tmp;
                ++start;--end;
            }
            else
                --end;
        }
        else
            ++start;
    }
    }
```
