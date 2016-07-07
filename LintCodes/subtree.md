---
title: subtree
date: 2016-06-15 10:07:16
categories: LintCode
tags: tree
---

## 子树

有两个不同大小的二进制树： T1 有上百万的节点； T2 有好几百的节点。请设计一种算法，判定 T2 是否为 T1的子树。

注意:若 T1 中存在从节点 n 开始的子树与 T2 相同，我们称 T2 是 T1 的子树。也就是说，如果在 T1 节点 n 处将树砍断，砍断的部分将与 T2 完全相同。

这题我愣了好久,老是 wrong answer,其实还是递归条件没有搞的很清楚。这一题我看网上其实还有一种解法,要利用到树的遍历。如果一棵树的前序和中序遍历已经确定,那么我们就可以唯一确定这一棵树。于是我们可以先遍历这两棵树并且分别构造前序和中序遍历的结果,之后单纯进行字符串比较即可。当然我还是使用的递归的方法,注意对每个节点判断是否是相同的树,之后再进行递归判定是否是子树。

```cpp
bool Identical(TreeNode* T1, TreeNode* T2)
{
    if (T1 == NULL && T2 == NULL) return true;
    if (T1 != NULL && T2 != NULL)
    {
        if (T1->val != T2->val) return false;
        bool left = Identical(T1->left, T2->left);
        bool right = Identical(T1->right, T2->right);
        return (left && right);
    }
    else return false;
}
bool isSubtree(TreeNode* T1, TreeNode* T2) {
    // write your code here
    if (T2 == NULL) return true;
    if (T1 == NULL) return false;

    bool root = Identical(T1, T2);
    if (root) return true;
    bool left = Identical(T1->left, T2);
    bool right = Identical(T1->right, T2);
    if (left || right) return true;
    else
    {
        return (isSubtree(T1->left, T2)||isSubtree(T1->right, T2));
    }
}
```
