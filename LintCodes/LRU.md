---
title: LRU
date: 2016-07-07 10:35:52
categories: LintCode
tags: LRU
---

## LRU缓存策略

为最近最少使用（LRU）缓存策略设计一个数据结构，它应该支持以下操作：获取数据（get）和写入数据（set）。
获取数据get(key)：如果缓存中存在key，则获取其数据值（通常是正数），否则返回-1。
写入数据set(key, value)：如果key还没有在缓存中，则写入其数据值。当缓存达到上限，它应该在写入新数据之前删除最近最少使用的数据用来腾出空闲位置。

这题我写了好久，老是有bug，ac不了。刚开始想使用 stl 里的 list 来实现的，但提示超时了。

```cpp
#include <list>

class LRUCache{
public:
    unordered_map<int, int> ump;
    list<int> l;
    int n;
    // @param capacity, an integer
    LRUCache(int capacity) {
        n = capacity;
    }

    // @return an integer
    int get(int key) {
        if (ump.count(key) > 0)
        {
            l.remove(key);
            l.push_front(key);
            return ump[key];
        }
        else
            return -1;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if (ump.find(key) != ump.end())
        {
            ump[key] = value;
            l.remove(key);
            l.push_front(key);
            return;
        }

        if (l.size() >= n)
        {
            int back = l.back();
            l.remove(back);
            ump.erase(back);
            ump[key] = value;
            l.push_front(key);
        }
        else
        {
            ump[key] = value;
            l.remove(key);
            l.push_front(key);
        }
    }
};
```

之后我自己实现了一个 double linked list，调了好久终于 ac 了，效率也还可以，击败了 leetcode 93%的 cpp 提交。我的思路是使用一个 map，里面存放key和节点对，另一个 list 里存储节点。每次操作都把最近访问的节点移动到 prev 节点的后面。

```cpp
struct DLNode
{
    int key;
    int val;
    DLNode* prev;
    DLNode* next;
    DLNode(int x = -1,int y = -1): key(x),val(y),prev(NULL),next(NULL){}
};

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        m_head = new DLNode();
        m_tail = new DLNode();
        m_head->next = m_tail;
        m_head->prev = NULL;
        m_tail->next = NULL;
        m_tail->prev = m_head;
    }

    // @return an integer
    int get(int key)
    {
        if (m_cache.find(key) != m_cache.end())
        {
            // key found
            DLNode* tnode = m_cache[key];
            move_front(tnode);
            return tnode->val;
        }
        else return -1;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value)
    {
        if (m_cache.find(key) != m_cache.end())
        {
            // key found
            DLNode* tnode = m_cache[key];
            tnode->val = value;
            move_front(tnode);
            return;
        }

        // key not found
        if (m_cache.size() >= m_capacity)
        {
            DLNode* back = m_tail->prev;
            back->prev->next = m_tail;
            m_tail->prev = back->prev;
            back->prev = NULL;
            back->next = NULL;
            m_cache.erase(back->key);
        }

        DLNode* tnode = new DLNode(key,value);
        put_front(tnode);
        m_cache[key] = tnode;
    }


private:
    DLNode* m_head;
    DLNode* m_tail;
    int     m_capacity;
    unordered_map<int, DLNode*> m_cache;

private:
    void move_front(DLNode* tnode)
    {
        tnode->next->prev = tnode->prev;
        tnode->prev->next = tnode->next;
        tnode->prev = m_head;
        tnode->next = m_head->next;
        m_head->next->prev = tnode;
        m_head->next = tnode;
    }

    void put_front(DLNode* tnode)
    {
        tnode->prev = m_head;
        tnode->next = m_head->next;
        m_head->next->prev = tnode;
        m_head->next = tnode;
    }
};
```
