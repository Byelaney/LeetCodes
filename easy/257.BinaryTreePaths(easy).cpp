/*

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> recHelper(TreeNode* root)
{
    vector<vector<string>> s;
    if (root == NULL) return s;
    vector<vector<string>> l = recHelper(root->left);
    vector<vector<string>> r = recHelper(root->right);
    for (auto c:l)
    {
        c.push_back(to_string(root->val));
        s.push_back(c);
    }

    for (auto c:r)
    {
        c.push_back(to_string(root->val));
        s.push_back(c);
    }


    if (s.size() < 1)
    {
        vector<string> vv;
        vv.push_back(to_string(root->val));
        s.push_back(vv);
    }
    return s;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<vector<string>> v = recHelper(root);
    vector<string> result;
    for (auto &s:v)
    {
        reverse(s.begin(), s.end());
        string str = "";
        for (int i = 0;i<s.size()-1;++i)
        {
            str += s[i];
            str.append("->");
        }
        str += s[s.size()-1];
        result.push_back(str);
    }
    return result;
}
};
