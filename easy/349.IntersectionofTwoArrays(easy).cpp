/*

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    if (nums1.size() == 0 || nums2.size() == 0) return v;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i = 0;int j = 0;
    int last = nums1[0];
    bool first_time = true;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
            ++i;
        else if (nums1[i] > nums2[j])
            ++j;
        else
        {
            if (nums1[i] != last || first_time)
            {
                v.push_back(nums1[i]);
                first_time = false;
            }
            last = nums1[i];
            ++i;++j;
        }
    }
    return v;
}
};
