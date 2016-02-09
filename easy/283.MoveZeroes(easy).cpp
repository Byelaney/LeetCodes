/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int prior_zero = 0;
    for (int i = 0;i<nums.size();i++)
    {
        if(nums[i] == 0)
            prior_zero++;
        else
        {
            nums[i-prior_zero] = nums[i];
        }
    }

    for (int i = int(nums.size()-prior_zero);i<nums.size();i++)
    {
        nums[i] = 0;
    }

}
};


/*

Store the number of 0s and then put them after the no-0 numbers.
This should take O(n) time complexity.


*/
