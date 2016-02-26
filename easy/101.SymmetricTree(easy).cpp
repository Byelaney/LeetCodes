/**

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

**/

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
    bool isSymmetric(TreeNode* root)
{
    return (root==NULL)||SymmetricHelp(root->left,root->right);
}


bool SymmetricHelp(TreeNode* left,TreeNode* right)
{
    if ( left==NULL || right==NULL)
        return (left==right);
    else
    {
        bool flag_val = (left->val == right->val);
        if (flag_val)
        {
            return SymmetricHelp(left->right, right->left) && SymmetricHelp(left->left, right->right);
        }else return false;
    }
}
};
