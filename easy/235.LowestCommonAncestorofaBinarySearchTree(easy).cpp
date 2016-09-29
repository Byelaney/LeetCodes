/*

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

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
    vector<TreeNode*> findNodePath(TreeNode* root, TreeNode* node)
{
    vector<TreeNode*> v;
    if (root == NULL) return v;
    if (root == node)
    {
        v.push_back(root);
        return v;
    }

    vector<TreeNode*> left = findNodePath(root->left, node);
    for (int i = 0;i<left.size();++i)
    {
        if (left[i] == node)
        {
            left.push_back(root);
            return left;
        }
    }

    vector<TreeNode*> right = findNodePath(root->right, node);
    for (int i = 0;i<right.size();++i)
    {
        if (right[i] == node)
        {
            right.push_back(root);
            return right;
        }
    }
    return v;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    if (p == NULL || q == NULL) return NULL;

    vector<TreeNode*> p_anc = findNodePath(root, p);
    vector<TreeNode*> q_anc = findNodePath(root, q);

    for (int i = 0;i<p_anc.size();++i)
    {
        for (int j = 0;j<q_anc.size();++j)
        {
            if (p_anc[i] == q_anc[j])
                return p_anc[i];
        }
    }
    return NULL;
}
};
