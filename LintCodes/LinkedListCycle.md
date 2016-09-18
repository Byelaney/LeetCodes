---
title: Linked List Cycle
date: 2016-06-07 21:34:53
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Linked List Cycle

Given a linked list, determine if it has a cycle in it.

```cpp
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
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
};



```
