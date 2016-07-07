---
title: recoverRotate
date: 2016-06-24 15:47:30
categories: LintCode
tags: reuse
---

## 恢复旋转排序数组

给定一个旋转排序数组，在原地恢复其排序。

什么是旋转数组？比如，原始数组为[1,2,3,4], 则其旋转数组可以是[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]

这题我的思路是这样的,首先把那个旋转点给找到,也就是最小值的坐标。之后从最大值(也就是最小值前面的那个点)开始往前,对每个值都从当前往后交换。寻找最小值用到了二份查找。

```cpp
int findMin(vector<int> &num) {
    int lo = 0;
    int hi = (int)num.size()-1;
    while(lo<hi){
        int mid = lo + (hi - lo)/2;
        if(num[mid]>num[hi]){
            lo = mid+1;
        }else if(num[mid]<num[hi]){
            hi = mid;
        }else{
            hi--;
        }
    }
    return lo;
}

void MySwap(vector<int> &nums,int start,int end)
{
    while (start <= end-1)
    {
        int tmp = nums[start];
        nums[start] = nums[start+1];
        nums[start+1] = tmp;
        ++start;
    }
}

void recoverRotatedSortedArray(vector<int> &nums) {
    int min_id = findMin(nums);
    int end = (int)nums.size()-1;
    for(int i = min_id-1;i>=0;--i)
    {
        MySwap(nums, i, end--);
    }
}
```
