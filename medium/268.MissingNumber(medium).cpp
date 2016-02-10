/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    unsigned long sum = nums.size() * (nums.size() + 1)/2;
    for(int i = 0;i<nums.size();i++)
    {
        sum -= nums[i];
    }
    return (int) sum;
}
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int result = 0;
    for(int i = 0;i<nums.size();i++)
    {
        result = result ^ (nums[i] ^ i);
    }

    return (int)(result ^ nums.size());
}
};


/*

This problem is easy.You can see this is an arithmetic sequence,
use S = (a1 + an) * n /2 to compute the sum.Then subtract each number to get 
the missing number.

However,there is another solution.You can use bit to solve it.Use XOR to
get the missing number which may seem a lot tricky.

*/
