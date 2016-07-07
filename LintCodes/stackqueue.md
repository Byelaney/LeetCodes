---
title: stackqueue
date: 2016-06-10 10:42:42
categories: LintCode
tags: Stack
---

## 用栈实现队列

正如标题所述，你需要使用两个栈来实现队列的一些操作。

队列应支持push(element)，pop() 和 top()，其中pop是弹出队列中的第一个(最前面的)元素。

pop和top方法都应该返回第一个元素的值。

仅使用两个栈来实现它，不使用任何其他数据结构，push，pop 和 top的复杂度都应该是均摊O(1)的。

这题其实不太难，很容易发现一个栈全部pop到另一个栈之后就满足队列的顺序了。

```cpp
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary

    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }

    int pop() {
        // write your code here
        if (stack2.size() == 0)
            fillup();

        if (stack2.size() == 0) return -1;
        else
        {
            int top = stack2.top();
            stack2.pop();
            return top;
        }

    }

    int top() {
        // write your code here
        if (stack2.size() == 0)
            fillup();

        if (stack2.size() == 0) return -1;
        else
            return stack2.top();
    }

    void fillup()
    {
        while (stack1.size() > 0)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
    }

};
```
