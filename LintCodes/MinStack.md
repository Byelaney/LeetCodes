---
title: MinStack
categories: LintCode
tags: Pointer
---

## MinStack

Implement a stack with min() function, which will return the smallest number in the stack.

It should support push, pop and min operation all in O(1) cost.

```cpp
class MinStack {
public:
    MinStack() {
        // do initialization if necessary
        head = NULL;
        minVal = 2147483647;
    }

    void push(int number) {
        if (head == NULL)
        {
            head = new ListNode(number);
            minVal = number;
        }
        else
        {
            ListNode* t = new ListNode(number);
            t->next = head;
            head = t;
            if (number < minVal)
                minVal = number;
        }
    }

    int pop() {
        if (head != NULL)
        {
            int val = head->val;
            head = head->next;
            if (val == minVal)
            {
                minVal = 2147483647;
                ListNode* tn = head;
                while (tn != NULL)
                {
                    if (tn->val < minVal)
                        minVal = tn->val;
                    tn = tn->next;
                }
            }
            return val;
        }
        else
            return 2147483647;
    }

    int min() {
        if (head != NULL) return minVal;
        else
            return 2147483647;
    }

private:
    ListNode* head;
    int minVal;
};

```
