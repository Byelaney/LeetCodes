/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<int> pascal;
    pascal.push_back(1);
    if (rowIndex == 0) return pascal;
    for (int i = 1;i<=rowIndex;++i)
    {
        vector<int> v(i+1);
        v[0] = 1;v[i] = 1;
        for (int j = 0;j<i-1;++j)
            v[j+1] = pascal[j] + pascal[j+1];
        pascal = v;
    }
    return pascal;
}
};
