---
title: hasRoute
date: 2016-06-29 10:40:02
categories: LintCode
tags: DirectedGraph
---

## 图中两个点之间的路线

给出一张有向图，设计一个算法判断两个点 s 与 t 之间是否存在路线。

简单的 BFS 一下就可以解决了。

```cpp
struct DirectedGraphNode {
         int label;
         vector<DirectedGraphNode *> neighbors;
         DirectedGraphNode(int x) : label(x) {};
};

bool hasRoute(vector<DirectedGraphNode*> graph,DirectedGraphNode* s, DirectedGraphNode* t)
{
    unordered_map<DirectedGraphNode*, bool> visited;
    queue<DirectedGraphNode*> q;
    q.push(s);
    while (q.size() > 0)
    {
        DirectedGraphNode* dgn = q.front();
        q.pop();
        if (dgn == t) return true;

        visited[dgn] = true;
        vector<DirectedGraphNode*> v = dgn->neighbors;
        for(int i = 0;i<v.size();++i)
        {
            if (visited.count(v[i]) > 0)
            {
                if (visited[v[i]] == true)
                    continue;
            }
            else
                q.push(v[i]);
        }
    }
    return false;
}
```
