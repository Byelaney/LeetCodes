---
title: threeSum
date: 2016-06-25 23:30:55
categories: LintCode
tags: Sum
---

## 三数之和

给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。在三元组(a, b, c)，要求a <= b <= c。

结果不能包含重复的三元组。

思路和二数之和很像，这里关键是对不重复的处理，我的处理比较粗糙写的比较丑陋。

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

vector<vector<int> > twoSum(vector<int> &nums,int sum,int start) {
    vector<vector<int>> v;
    if (nums.size() == 0) return v;
    if (nums[0] > 0 || nums[nums.size()-1] < 0) return v;

    for(int i = start;i<nums.size();++i)
    {
        int aim = sum-nums[i];
        int idx = binarySearch(nums, aim, i+1, (int)nums.size()-1);
        if (idx == -1)
            continue;
        else
        {
                vector<int> vv;
                vv.push_back(nums[i]);
                vv.push_back(nums[idx]);
                v.push_back(vv);
        }
    }
    return v;
}

bool isUnique(vector<int> tmpv,vector<int> v2)
{
    sort(tmpv.begin(), tmpv.end());
    sort(v2.begin(), v2.end());

    if(tmpv[0] == v2[0])
    {
        if (tmpv[1] == v2[1])
        {
            if (tmpv[2] == v2[2])
                return false;
            else return true;
        }
        else
            return true;
    }
    else return true;
}

vector<vector<int> > threeSum(vector<int> &nums) {
    vector<vector<int>> v;
    if (nums.size() == 0) return v;
    sort(nums.begin(), nums.end());

    if (nums[0] > 0 || nums[nums.size()-1] < 0) return v;
    for(int i = 0;i<nums.size();++i)
    {
        int sum = -nums[i];
        vector<vector<int>> v2 = twoSum(nums, sum,i+1);
        if(v2.size() > 0)
        {
            for(int j = 0;j<v2.size();++j)
            {
                vector<int> v3;
                v3.push_back(nums[i]);
                v3.push_back(v2[j][0]);
                v3.push_back(v2[j][1]);

                bool Unique = true;
                for(int k = 0;k<v.size();++k)
                {
                    vector<int> vk = v[k];
                    if (!isUnique(vk,v3))
                    {
                        Unique = false;
                        break;
                    }
                }
                if (Unique)
                    v.push_back(v3);
            }
        }
    }
    return v;
}
```
