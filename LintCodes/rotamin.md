---
title: rotamin
date: 2016-06-10 08:28:34
categories: LintCode
tags: BinarySearch
---

## 寻找旋转排序数组中的最小值

假设一个旋转排序的数组其起始位置是未知的（比如[0 1 2 4 5 6 7] 可能变成是[4 5 6 7 0 1 2]）。

你需要找到其中最小的元素。

你可以假设数组中不存在重复的元素。

找最小的话遍历一遍就行了，或者用二分查找。

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
    return num[lo];
}
```
