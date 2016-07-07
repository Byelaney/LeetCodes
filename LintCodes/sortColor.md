---
title: sortColor
date: 2016-07-04 09:34:43
categories: LintCode
tags: pointer
---

## 颜色分类

给定一个包含红，白，蓝且长度为 n 的数组，将数组元素进行分类使相同颜色的元素相邻，并按照红、白、蓝的顺序进行排序。我们可以使用整数 0，1 和 2 分别代表红，白，蓝。
不能使用代码库中的排序函数来解决这个问题。排序需要在原数组中进行。

睡了一觉起来其实我思路是有的。遍历数组的时候，如果发现 0，就和开头的指针交换，如果发现是 2，就和尾部的指针交换，这样的话所有的 0 都在头部 所有的 2 都在尾部，中间的自然就全都是1了。当然写的时候要注意边界条件的判断。一般遇到这种问题的话还是直接排序吧。。。想那么久有时候吃力不讨好。

```cpp
void sortColors(vector<int> &nums) {
    int start = 0;
    int end = (int)nums.size()-1;
    int i = 0;
    while (i <= end)
    {
        if (nums[i] == 0)
            swap(nums[i++], nums[start++]);
        else if (nums[i] == 2)
            swap(nums[i], nums[end--]);
        else
            i++;
    }
}
```
