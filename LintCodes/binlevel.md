---
title: binlevel
date: 2016-07-04 16:50:36
categories: LintCode
tags: BFS
---

## 二叉树的层次遍历

给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）

[
  [3],
  [9,20],
  [15,7]
]

显然这题目涉及到宽度优先搜索(BFS)，但关键就是这个 level 的问题。这里真没想出来，我也是看了提示。可以用当时的队列的元素个数来表示这个 level。

```cpp
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> v;
    if (root == NULL) return v;

    queue<TreeNode*> que;
    que.push(root);
    while (que.size() > 0)
    {
        vector<int> lv;
        int level_len = (int)que.size();
        for (int i = 0;i<level_len;++i)
        {
            TreeNode* tmp = que.front();que.pop();
            lv.push_back(tmp->val);
            if (tmp->left != NULL)
                que.push(tmp->left);
            if (tmp->right != NULL)
                que.push(tmp->right);
        }
        v.push_back(lv);
    }
    return v;
}
```
