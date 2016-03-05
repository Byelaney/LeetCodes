/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root != NULL)
    {   vector<int> v1,v2;
        v1 = inorderTraversal(root->left);
        for(int i = 0;i<v1.size();i++)
            v.push_back(v1[i]);
        v.push_back(root->val);
        v2 = inorderTraversal(root->right);
        for(int i = 0;i<v2.size();i++)
            v.push_back(v2[i]);
    }
    return v;
}
};



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    stack<TreeNode*> s;
    if (root != NULL)
    {
        s.push(root);
        while (!s.empty())
        {
            TreeNode* T = s.top();
            s.pop();
            if ( T->left == NULL)
            {
                v.push_back(T->val);
                if(T->right != NULL)
                    s.push(T->right);
            }
            else
            {
                TreeNode* tmp = T->left;
                T->left = NULL;
                s.push(T);
                s.push(tmp);
            }
        }
    }
    return v;
}
};
