---
title: segTreeModify
date: 2016-06-27 23:21:20
categories: LintCode
tags: SegTree
---

## 线段树的修改

对于一棵 最大线段树, 每个节点包含一个额外的 max 属性，用于存储该节点所代表区间的最大值。设计一个 modify 的方法，接受三个参数 root、 index 和 value。该方法将 root 为跟的线段树中 [start, end] = [index, index] 的节点修改为了新的 value ，并确保在修改后，线段树的每个节点的 max 属性仍然具有正确的值。
题目比较基础，按照提示进行递归即可。

先找到那个 target 节点然后修改它。然后再从根节点进行调整即可。


```cpp
SegmentTreeNode* aimNode(SegmentTreeNode* root,int index)
{
    if (root == NULL) return NULL;
    if (root->start == index && root->end == index) return root;

    int left = (root->end-root->start)/2+root->start;
    if (index >= root->start && index <= left)
        return aimNode(root->left, index);
    else
        return aimNode(root->right, index);
}

int updateMax(SegmentTreeNode* root)
{
    if (root == NULL) return 0;
    if (root->start == root->end) return root->max;

    int leftMax = updateMax(root->left);
    int rightMax = updateMax(root->right);

    root->max = max(leftMax,rightMax);
    return root->max;
}

void modify(SegmentTreeNode* root, int index, int value) {
    SegmentTreeNode* target = aimNode(root, index);
    if (target != NULL)
    {
        target->max = value;
        updateMax(root);
    }
}
```
