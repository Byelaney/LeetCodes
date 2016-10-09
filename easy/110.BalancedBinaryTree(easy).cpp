/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    int nodeDepth(TreeNode *root)
{
    if (root == NULL) return 0;

    int left = nodeDepth(root->left);
    int right = nodeDepth(root->right);
    return max(left,right) + 1;
}
bool isBalanced(TreeNode *root) {
    if (root == NULL) return true;

    int left = nodeDepth(root->left);
    int right = nodeDepth(root->right);

    if (max(left,right) - min(left,right) > 1)
        return false;
    else
    {
        bool isLeft = isBalanced(root->left);
        bool isRight = isBalanced(root->right);
        return (isLeft&&isRight);
    }
}
};
