---
title: cycleList
date: 2016-07-04 11:21:39
categories: LintCode
tags: physics
---

## 带环链表 II

给定一个链表，如果链表中存在环，则返回到链表中环的起始节点的值，如果没有环，返回null。

画图理解比较好，比较简明地来说就是 2(a+b) = a + (b+c) + b。也就是说 a = c，a 是从起点到环入口的距离，b 是两个指针相遇，入口到这个相遇点的距离，c 是环中剩下的距离。

```cpp
ListNode *detectCycle(ListNode *head) {
        // write your code here
        ListNode* ptr1,* ptr2;
        if(head == NULL)
            return NULL;
        ptr1 = head ;
        ptr2 = head;

        while(ptr2->next != NULL && ptr2->next->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2)
            {
                ptr1 = head;
                while(ptr1 != ptr2)
                {
                    ptr2 = ptr2->next;
                    ptr1 = ptr1->next;
                }
                return ptr1;
            }

        }
        return NULL;
    }
```
