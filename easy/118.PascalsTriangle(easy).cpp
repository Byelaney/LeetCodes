/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    if (numRows == 0) return pascal;
    vector<int> base;
    base.push_back(1);
    pascal.push_back(base);
    for (int i = 1;i<numRows;++i)
    {
        vector<int> v(i+1);
        v[0] = 1;v[i] = 1;
        for (int j = 0;j<i-1;++j)
            v[j+1] = pascal[i-1][j] + pascal[i-1][j+1];
        pascal.push_back(v);
    }
    return pascal;
}
};
