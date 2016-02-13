/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> a;
    vector<int> vt;
    for (int i = 0;i<nums.size();i++)
    {
        if (a.count(target - nums[i]))
        {
            vt.push_back(i);
            vt.push_back(a.find(target - nums[i])->second);
        }
        else
            a[nums[i]] = i;
    }
    vector<int> ans;
    ans.push_back(vt[0]+1);
    ans.push_back(vt[1]+1);
    if (ans[0] > ans[1])
        swap(ans[0], ans[1]);
    return ans;
}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    int a = 0;
    int b = (int)tmp.size()-1;

    while (a < b)
    {
        if (tmp[a] + tmp[b] < target)
            a++;
        else if (tmp[a] + tmp[b] > target)
            b--;
        else
            break;
    }

    vector<int> ans;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]==tmp[a]) ans.push_back(i+1);
        else if (nums[i]==tmp[b]) ans.push_back(i+1);
    }

    if (ans[0]>ans[1])
        swap(ans[0], ans[1]);
    return ans;


}
};


/*

Actually this problem is quite straightforward.Intuitively you want to sort the
array then use binary search to find the answer.But the implementation could be
tricky.So I would prefer the Map solution.Use map to store and access the
visited numbers.The algorithm is also quite straightforward.

*/
