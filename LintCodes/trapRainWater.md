---
title: trapRainWater
date: 2016-07-13 23:05:27
categories: LintCode
tags: Pointer
---

## 接雨水

给出 n 个非负整数，代表一张X轴上每个区域宽度为 1 的海拔图, 计算这个海拔图最多能接住多少（面积）雨水。

这题我没有想出来，最佳解的答案也没有看懂。

```cpp
int trapRainWater(vector<int>& height) {
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    if (height.size() == 0) return 0;

    int left[height.size()];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[height.size()];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = height[0];
    for (int i = 1; i < height.size(); i++)
        left[i] = max(left[i-1], height[i]);

    // Fill right array
    right[height.size()-1] = height[height.size()-1];
    for (int i = (int)height.size()-2; i >= 0; i--)
        right[i] = max(right[i+1], height[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < height.size(); i++)
        water += min(left[i],right[i]) - height[i];

    return water;
}
```
