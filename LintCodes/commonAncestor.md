---
title: commonAncestor
date: 2016-06-18 09:48:14
categories: LintCode
tags: Tree
---

## 最近公共祖先

给定一棵二叉树，找到两个节点的最近公共父节点(LCA)。

这题其实有点难度,我一开始的想法是先对两棵树分别做 bfs,然后存在数组里,空节点也要存。这样的话假设树 T[i],那么它的子节点是很容易获取的, 也就是 T[2i+1] 和 T[2i+2]。这时候只要从数组的右边往左边扫描不断寻找各自的父亲节点,发现的第一个就是最近的公共祖先了,后来觉得好像这样写挺麻烦的。关键就在找到各自的父亲节点,我就单独提取出来写个找父亲节点的方法,然后再比较即可。我的写法比较耗费空间存储,想法很简单,也是递归,只要子节点里面不含有目标节点,就不把它添加到当前的 vector 里去。

```cpp
vector<TreeNode*> findDad(TreeNode* root,TreeNode* t)
{
    vector<TreeNode*> v;
    if (root == NULL) return v;
    if (root == t)
    {
        v.push_back(root);
        return v;
    }
    v.push_back(root);
    vector<TreeNode*> left = findDad(root->left, t);
    bool l1 = false;
    bool r1 = false;
    vector<TreeNode*> right = findDad(root->right, t);
    for(int i = (int)left.size()-1;i>=0;--i)
        if (left[i] == t)
            l1 = true;
    for(int i = (int)right.size()-1;i>=0;--i)
        if (right[i] == t)
            r1 = true;

    if (l1)
    {
        for(int i = 0;i<left.size();++i)
            v.push_back(left[i]);
    }
    if (r1)
    {
        for(int i = 0;i<right.size();++i)
            v.push_back(right[i]);
    }
    return v;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* A, TreeNode* B) {
    vector<TreeNode*> Dad1 = findDad(root, A);
    vector<TreeNode*> Dad2 = findDad(root, B);
    int p1 = 0;
    int p2 = 0;
    while (p1 < Dad1.size() && p2 < Dad2.size())
    {
        if (Dad1[p1] != Dad2[p2])
            break;
        ++p1;++p2;
    }
    return Dad1[p1-1];
}
```
