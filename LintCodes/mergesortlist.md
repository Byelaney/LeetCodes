---
title: mergesortlist
date: 2016-06-12 15:07:15
categories: LintCode
tags: Merge
---

## 合并两个排序链表

将两个排序链表合并为一个新的排序链表

类似 **Merge Sort** 的最后一步。

```cpp
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // write your code here
    ListNode* prehead = new ListNode(0);
    ListNode* tmp = prehead;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            tmp->next = l1;
            l1 = l1->next;
        }
        else
        {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    if (l1 == NULL) tmp->next = l2;
    else tmp->next = l1;
    return prehead->next;
}
```
