---
title: divdlist
date: 2016-06-17 16:09:39
categories: LintCode
tags: LinkedList
---

## 链表划分

给定一个单链表和数值x，划分链表使得所有小于x的节点排在大于等于x的节点之前。你应该保留两部分内链表节点原有的相对顺序。

不知道有什么更简洁的办法,我是用几个指针记录节点的。本身并不难,考的基础题。

```cpp
ListNode *partition(ListNode* head, int x) {
    ListNode* tmp = head;
    ListNode* left = new ListNode(-1);
    ListNode* headL = left;
    ListNode* right = new ListNode(-1);
    ListNode* headR = right;
    while (tmp != NULL)
    {
        if (tmp->val < x)
        {
            left->next = tmp;
            left = left->next;
        }
        else
        {
            right->next = tmp;
            right = right->next;
        }
        tmp = tmp->next;
    }
    right->next = NULL;
    left->next = headR->next;
    return headL->next;
}
```
