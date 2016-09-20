/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

class Solution {
public:
    int trap(vector<int>& height) {
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    if (height.size() == 0) return 0;

    int left[height.size()];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[height.size()];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = height[0];
    for (int i = 1; i < height.size(); i++)
        left[i] = max(left[i-1], height[i]);

    // Fill right array
    right[height.size()-1] = height[height.size()-1];
    for (int i = (int)height.size()-2; i >= 0; i--)
        right[i] = max(right[i+1], height[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < height.size(); i++)
        water += min(left[i],right[i]) - height[i];

    return water;
}
};
