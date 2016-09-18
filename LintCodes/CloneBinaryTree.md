---
title: Clone Binary Tree
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Clone Binary Tree

For the given binary tree, return a deep copy of it.

```cpp
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
    if (root == NULL) return NULL;
    TreeNode* rt = new TreeNode(root->val);
    rt->left = cloneTree(root->left);
    rt->right = cloneTree(root->right);
    return rt;
}
};
```
