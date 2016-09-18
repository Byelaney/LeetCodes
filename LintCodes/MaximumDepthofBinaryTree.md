---
title: Maximum Depth of Binary Tree
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(dfs(root->left), dfs(root->right));
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
```
