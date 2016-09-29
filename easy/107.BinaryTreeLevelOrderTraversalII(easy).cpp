/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> v;
    if (root == NULL) return v;
    queue<TreeNode*> treeQue;
    queue<int> levQue;
    int lastLev = 1;
    vector<int> v_tmp;

    treeQue.push(root);
    levQue.push(1);

    while (treeQue.size() > 0)
    {
        TreeNode* cur_node = treeQue.front();
        treeQue.pop();
        int cur_lev = levQue.front();
        levQue.pop();

        if (cur_lev != lastLev)
        {
            v.push_back(v_tmp);
            v_tmp.clear();
            lastLev = cur_lev;
        }

        v_tmp.push_back(cur_node->val);
        if (cur_node->left != NULL)
        {
            treeQue.push(cur_node->left);
            levQue.push(cur_lev+1);
        }
        if (cur_node->right != NULL)
        {
            treeQue.push(cur_node->right);
            levQue.push(cur_lev+1);
        }
    }
    if (v_tmp.size() > 0)
        v.push_back(v_tmp);

    reverse(v.begin(), v.end());
    return v;
}
};
