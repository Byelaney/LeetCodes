---
title: swapListNode
date: 2016-06-19 18:03:08
categories: LintCode
tags: LinkedList
---

## 两两交换链表中的节点

给一个链表，两两交换其中的节点，然后返回交换后的链表。

双指针加上一个存储临时节点的指针即可解决。

```cpp
ListNode* swapPairs(ListNode* head) {
    ListNode* p1 = head;
    ListNode* p2;
    if (p1 == NULL) return head;
    p2 = p1->next;
    if (p2 == NULL) return p1;
    head = p2;

    ListNode* lastOne = new ListNode(-1); //dummy head
    while (p1 != NULL && p2 != NULL)
    {
        ListNode* next = p2->next;
        // swap p1 and p2
        p2->next = p1;
        p1->next = next;

        lastOne->next = p2;
        lastOne = p1;
        if (next != NULL)
        {
            p1 = next;
            p2 = p1->next;
        }
        else
        {
            p1 = next;
            p2 = NULL;
        }
    }
    return head;
}
```
