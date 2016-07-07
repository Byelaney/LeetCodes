---
title: wigglesort
date: 2016-06-10 10:15:44
categories: LintCode
tags: Sort
---

给你一个没有排序的数组，请将原数组就地重新排列满足如下性质:
nums[0] <= nums[1] >= nums[2] <= nums[3]....

要求: 不能使用额外数组。

我把这题想的太复杂了...想成先排序再交换，其实只要遍历一遍，同时把 **nums[i] 与 nums[i+1]** 不满足以上关系的交换就好了。

```cpp
void wiggleSort(vector<int>& nums) {
    // Write your code here
    int n = (int)nums.size();
    if (n < 2)
        return;
    for (int i = 1; i < n; ++i) {
        if (((i % 2 == 1) && nums[i] < nums[i - 1]) || ((i % 2 == 0) && nums[i] > nums[i - 1])) {
            int temp = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = temp;
        }
    }
}
```
