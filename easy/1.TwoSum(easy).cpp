/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> myvector(nums.begin(),nums.end());
    vector<int> v;
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = (int)nums.size()-1;
    int v1,v2;
    v1 = 0;
    v2 = 0;
    while(i <= j)
    {
        if(nums[i] + nums[j] == target)
        {
            v1 = nums[i];
            v2 = nums[j];
            break;
        }

        if(nums[i] + nums[j] > target)
            j--;

        if(nums[i] + nums[j] < target)
            ++i;
    }

    map<int,int> mp;

    for(int i = 0;i<myvector.size();++i)
    {
        if(myvector[i] == v1)
            mp[i] = 1;

        if(myvector[i] == v2)
            mp[i] = 1;
    }

    for(map<int,int>::iterator it = mp.begin();it!=mp.end();++it)
        v.push_back(it->first);

    return v;
}
};
