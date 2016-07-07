---
title: ringlist
date: 2016-06-08 16:28:52
categories: LintCode
tags: pro_magic
---

## 带环链表


给定一个链表，判断它是否有环。

这里只要用龟兔赛跑的算法就可以了，如果有环的话，乌龟一定会追上兔子！(确定不是兔子套圈乌龟吗...)

```cpp
bool hasCycle(ListNode* head) {
        if (head == NULL) return false;
        ListNode* turtle = head;
        ListNode* hare = head->next;
        while (hare != NULL && turtle != NULL)
        {
            if (hare == turtle) return true;
            if (hare->next == NULL) return false;
            hare = hare->next;
            hare = hare->next;
            turtle = turtle->next;
        }
        return false;
    }
```
