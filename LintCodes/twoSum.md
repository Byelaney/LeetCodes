---
title: twoSum
date: 2016-06-25 23:28:48
categories: LintCode
tags: Binary
---

## 两数之和

给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。你可以假设只有一组答案。

主要思路并不是特别难,就是排序之后进行对每一个数,在剩下的数组里进行二分查找。

```cpp
int binarySearch(vector<int> &nums,int aim,int start,int end)
{
    while (start <= end)
    {
        int mid = (end-start)/2 + start;
        if (nums[mid] == aim) return mid;
        else if(nums[mid] < aim)
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> v;
    if (nums.size() == 0) return v;
    unordered_map<int, vector<int>> umap;
    for(int i = 0;i<nums.size();++i)
    {
        if (umap.count(nums[i]) == 0)
        {
            vector<int> v3;
            v3.push_back(i);
            umap[nums[i]] = v3;
        }
        else
        {
            vector<int> v4 = umap[nums[i]];
            v4.push_back(i);
            umap[nums[i]] = v4;
        }
    }

    sort(nums.begin(), nums.end());
    for(int i = 0;i<nums.size();++i)
    {
        int aim = target-nums[i];
        int idx = binarySearch(nums, aim, i+1, (int)nums.size()-1);
        if (idx == -1)
            continue;
        else
        {
            set<int> s;
            vector<int> v1 = umap[nums[i]];
            vector<int> v2 = umap[nums[idx]];
            for(int k = 0;k<v1.size();++k)
                s.insert(v1[k]);
            for(int k = 0;k<v2.size();++k)
                s.insert(v2[k]);

            for(set<int>::iterator it = s.begin();it != s.end();++it)
                v.push_back(*it+1);

            sort(v.begin(), v.end());
            return v;
        }
    }
    return v;
}
```
