---
title: bstinterval
date: 2016-06-12 15:28:50
categories: LintCode
tags: Tree
---

## 二叉查找树中搜索区间

给定两个值 k1 和 k2（k1 < k2）和一个二叉查找树的根节点。找到树中所有值在 k1 到 k2 范围内的节点。即打印所有x (k1 <= x <= k2) 其中 x 是二叉查找树的中的节点值。返回所有升序的节点值。

基本上还是递归的思想，还是比较简单的。

```cpp
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
```
