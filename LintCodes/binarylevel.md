---
title: binarylevel
date: 2016-06-08 16:53:31
categories: LintCode
tags: recursive
---

## 二叉树的层次遍历 II

给出一棵二叉树，返回其节点值从底向上的层次序遍历（按从叶节点所在层到根节点所在的层遍历，然后逐层从左往右遍历）

我是怎么想的呢，如果我现在在根节点，已经有了左右两节点的 **vector<vector<int>>**,该怎么做呢？其实觉得又和 **merge sort** 有点类似，从左 **vector** 到右 **vector**，取出来存入新的里面。代码写得太啰嗦了，水平有限...

```cpp
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> v = Helper(root);
    reverse(v.begin(), v.end());
    return v;
}

vector<vector<int>> Helper(TreeNode* root)
{
    vector<vector<int>> v;
    vector<int> vi,vii;

    if (root == NULL) return v;

    vi.push_back(root->val);
    v.push_back(vi);
    if (root->left == NULL && root->right == NULL)
        return v;
    else
    {
        vector<vector<int>> lf = Helper(root->left);
        vector<vector<int>> rg = Helper(root->right);

        int i = 0;
        int j = 0;
        while (i < lf.size() && j < rg.size())
        {
            vector<int> vv;
            for(int ii = 0;ii<lf[i].size();++ii)
            {
                vv.push_back(lf[i][ii]);
            }
            for(int ii = 0;ii<rg[j].size();++ii)
            {
                vv.push_back(rg[j][ii]);
            }
            v.push_back(vv);
            ++i;++j;
        }

        while (i < lf.size())
        {
            vector<int> vv;
            for(int ii = 0;ii<lf[i].size();++ii)
            {
                vv.push_back(lf[i][ii]);
            }
            v.push_back(vv);
            ++i;
        }

        while (j < rg.size())
        {
            vector<int> vv;
            for(int ii = 0;ii<rg[j].size();++ii)
            {
                vv.push_back(rg[j][ii]);
            }
            v.push_back(vv);
            ++j;
        }

    }
    return v;
}
```
