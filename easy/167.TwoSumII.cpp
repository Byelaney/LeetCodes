/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

class Solution {
public:
    int binarySearch(vector<int>& numbers, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (end-start)/2 + start;
        if (numbers[mid] == target)
            return mid;
        else if (numbers[mid] > target)
            end = mid -1;
        else
            start = mid + 1;
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> v;
    for (int i = 0;i<numbers.size();++i)
    {
        int idx = binarySearch(numbers, target - numbers[i], i+1, (int)numbers.size()-1);
        if (idx != -1)
        {
            v.push_back(i+1);
            v.push_back(idx+1);
        }
    }
    return v;
}
};
