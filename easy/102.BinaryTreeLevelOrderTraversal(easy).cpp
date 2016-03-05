/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> v;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;

    if (root != NULL)
        q1.push(root);

    while ((!q1.empty()) || (!q2.empty()))
    {
        vector<int> vt;
        if (q1.empty())
        {
            //q2 is not empty
            while (!q2.empty())
            {
                TreeNode* T = q2.front();
                q2.pop();
                vt.push_back(T->val);
                if (T->left != NULL)
                    q1.push(T->left);
                if (T->right != NULL)
                    q1.push(T->right);
            }
        }
        else
        {
            while (!q1.empty())
            {
                TreeNode* T = q1.front();
                q1.pop();
                vt.push_back(T->val);
                if (T->left != NULL)
                    q2.push(T->left);
                if (T->right != NULL)
                    q2.push(T->right);
            }
        }
        v.push_back(vt);
    }
    return v;
}
};

/*

Use two queue to operate.

*/
