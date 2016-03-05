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
    if (root != NULL)
    {   vector<int> v1,v2;
        v1 = postorderTraversal(root->left);
        for(int i = 0;i<v1.size();i++)
            v.push_back(v1[i]);
        v2 = postorderTraversal(root->right);
        for(int i = 0;i<v2.size();i++)
            v.push_back(v2[i]);
        v.push_back(root->val);
    }
    return v;
}
};

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
