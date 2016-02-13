/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
public:
stack<int> a1;
stack<int> a2;
void push(int x) {
    a1.push(x);
    if(a2.empty() || x<=getMin())
        a2.push(x);
}

void pop() {
    if (!a1.empty())
    {
        if (a1.top() == getMin())
        {
            a2.pop();
        }
        a1.pop();
    }

}

int top() {
    return a1.top();
}

int getMin() {
    return a2.top();
}
};


/*

The key point is you do not have to store every element in min stack.

*/
