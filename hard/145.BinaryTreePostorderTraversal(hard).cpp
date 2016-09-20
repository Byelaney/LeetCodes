/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    stack<TreeNode*> s;
    if (root != NULL)
    {
        s.push(root);
        while (!s.empty())
        {
            TreeNode* T = s.top();
            s.pop();
            if (T->left == NULL && T->right == NULL)
                v.push_back(T->val);
            else if (T->left != NULL && T->right != NULL)
            {
                TreeNode* left = T->left;
                TreeNode* right = T->right;
                T->left = NULL;
                T->right = NULL;
                s.push(T);
                s.push(right);
                s.push(left);
            }
            else if (T->left != NULL)
            {
                TreeNode* left = T->left;
                T->left = NULL;
                s.push(T);
                s.push(left);
            }
            else if (T->right != NULL)
            {
                TreeNode* right = T->right;
                T->right = NULL;
                s.push(T);
                s.push(right);
            }
        }
    }
    return v;
}
};
