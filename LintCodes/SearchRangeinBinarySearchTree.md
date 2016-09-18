---
title: Search Range in Binary Search Tree
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Search Range in Binary Search Tree

Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.

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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
    // write your code here
    vector<int> v;
    if (root == NULL) return v;
    if (root->val < k1) return searchRange(root->right, k1, k2);
    if (root->val > k2) return searchRange(root->left, k1, k2);

    vector<int> left = searchRange(root->left, k1, k2);
    vector<int> right = searchRange(root->right, k1, k2);
    for(int i = 0;i<left.size();++i)
        v.push_back(left[i]);
    v.push_back(root->val);
    for(int i = 0;i<right.size();++i)
        v.push_back(right[i]);

    return v;
}
};
```
