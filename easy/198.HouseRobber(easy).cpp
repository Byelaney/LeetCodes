/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {
public:
    int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0],nums[1]);

    long long dp_prev = nums[0];
    long long dp_cur = 0;
    bool current = false;
    if (nums[0] < nums[1])
    {
        current = true;
        dp_cur = nums[1];
    }
    else
        dp_cur = nums[0];

    for(int i = 2;i<nums.size();++i)
    {
        if (current)
        {
            if (dp_prev + nums[i] > dp_cur)
            {
                long long tmp = dp_cur;
                dp_cur = dp_prev + nums[i];
                dp_prev = tmp;
            }
            else
            {
                current = false;
                dp_prev = dp_cur;
            }
        }
        else
        {
            current = true;
            dp_prev = dp_cur;
            dp_cur += nums[i];
        }
    }
    return dp_cur;
    }
};
