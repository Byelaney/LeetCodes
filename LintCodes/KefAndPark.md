---
title: KefAndPark
date: 2016-06-07 21:57:52
categories: codeforces
tags: [ACM,DFS]
mathjax: true
---

## Kefa And Park

Kefa decided to celebrate his first big salary by going to the restaurant.

He lives by an unusual park. The park is a rooted tree consisting of n vertices with the root at vertex 1. Vertex 1 also contains Kefa's house. Unfortunaely for our hero, the park also contains cats. Kefa has already found out what are the vertices with cats in them.

The leaf vertices of the park contain restaurants. Kefa wants to choose a restaurant where he will go, but unfortunately he is very afraid of cats, so there is no way he will go to the restaurant if the path from the restaurant to his house contains more than m consecutive vertices with cats.

Your task is to help Kefa count the number of restaurants where he can go.

Input
The first line contains two integers, n and m (2 ≤ n ≤ 10^5, 1 ≤ m ≤ n) — the number of vertices of the tree and the maximum number of consecutive vertices with cats that is still ok for Kefa.

The second line contains n integers a1, a2, ..., an, where each ai either equals to 0 (then vertex i has no cat), or equals to 1 (then vertex i has a cat).

Next n - 1 lines contains the edges of the tree in the format "xi yi" (without the quotes) (1 ≤ xi, yi ≤ n, xi ≠ yi), where xi and yi are the vertices of the tree, connected by an edge.

It is guaranteed that the given set of edges specifies a tree.

Output
A single integer — the number of distinct leaves of a tree the path to which from Kefa's home contains at most m consecutive vertices with cats.

more specific info see [C. Kefa and Park](http://codeforces.com/problemset/problem/580/C)


一开始的时候我没有搞清楚题意，用树的观点去做的时候误以为数字小的节点就是数字大的节点的父节点，写完后发现到第八还是第九个测试案例的时候就失败了。比如某一个测试用例的 [4,2]， 这里4反而是2的父节点。于是我尝试换一个角度去思考，用图的概念来处理，算法本身是很简单的一个 dfs，难点就在实现部分了。我用了存放 vector 的数组 e，vector 里存放每个节点的邻居节点。特别注意的是添加邻居节点的时候要注意涉及到的两个节点都要添加。之后就是 dfs 的部分了，dfs 人人都会，难点在于和题目本身结合，如何去表达连续节点有猫的个数不超过 m 这个条件。

```cpp
// v is current vertice
void dfs(int v,int anc,int c)
{
    if(cats[v]) ++c;
    else c = 0;
    if(c > m) return;//too many cats!
    bool currentLeaf = true;//assume current is a leaf
    rep(i, e[v].size())
    {
        int adjancent = e[v][i];
        if(adjancent != anc)
        {
            currentLeaf = false;
            dfs(adjancent, v, c);
        }
    }
    if(currentLeaf) ++choices;
}
```

主要就是三个参数，当前要处理的节点，之前的那个节点，以及之前的连续节点有猫的个数。如果当前节点的 vector 中只含有之前的那个节点的话就说明当前节点是叶子节点。详细代码请参考 [My AC code](http://codeforces.com/contest/580/submission/18152137)
