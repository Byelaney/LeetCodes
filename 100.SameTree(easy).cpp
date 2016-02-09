/*

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p!=NULL && q!=NULL)
    {
        if (p->val == q->val)
        {
            bool left_right = false;
            left_right = (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
            return left_right;
        }
        else
            return false;
    }
    else if (p==NULL && q==NULL)
        return true;
    else
        return false;
}
};


/*

Still, use recursion to make life better!

*/
