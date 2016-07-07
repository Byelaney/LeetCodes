---
title: twolistIsect
date: 2016-06-10 15:52:24
categories: LintCode
tags: List
---

## 两个链表的交叉

请写一个程序，找到两个单链表最开始的交叉节点。

这题思路要从链表解放，心里要有一个 **距离** 的概念，我并不确定我是不是最佳解法，但我是这样想的，我们可以得到两个链表的长度 **n1 和 n2**(通过遍历链表直到为空)，然后计算 **abs(n1-n2)** ，再让那个较长的链表从头开始遍历 **abs(n1-n2)** 次，之后再和另一个链表同时遍历并且比较节点是否相同即可。代码写的一如既往的很啰嗦。。。可能跟我人本身有关，不喜欢太复杂的东西，喜欢简单直白的美。(其实是毫无内涵)

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // write your code here
    int n1 = 0;
    int n2 = 0;
    ListNode* node1 = headA;
    ListNode* node2 = headB;

    if (node1 == NULL || node2 == NULL) return NULL;

    while(1)
    {
        if (node1 == node2) return node1;

        node1 = node1->next;
        node2 = node2->next;
        ++n1;++n2;

        if(node1 == NULL || node2 == NULL)
            break;
    }

    if (node1 == NULL)
    {
        while(node2 != NULL)
        {
            node2 = node2->next;
            ++n2;
        }

        ListNode* node = headB;
        for(int i = 0;i<n2-n1;++i)
        {
            node = node->next;
        }

        ListNode* nodea = headA;
        ListNode* res = IntersectSL(nodea,node);
        return res;
    }
    else if (node2 == NULL)
    {
        while(node1 != NULL)
        {
            node1 = node1->next;
            ++n1;
        }

        ListNode* node = headA;
        for(int i = 0;i<n1-n2;++i)
        {
            node = node->next;
        }
        ListNode* nodeb = headB;
        ListNode* res = IntersectSL(nodeb,node);
        return res;
    }
    else
    {
        // l1 and l2 the same length
        return NULL;
    }
}

ListNode* IntersectSL(ListNode* n1,ListNode* n2)
{
    while(n1 != NULL && n2 != NULL)
    {
        if (n1 == n2)
            return n1;
        n1 = n1->next;
        n2 = n2->next;
    }
    return NULL;
}

```
