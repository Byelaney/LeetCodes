/*

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    ListNode * turtle = head;
    ListNode * rabbit = head;
    while (turtle != NULL && rabbit != NULL)
    {
        if (rabbit->next == NULL || turtle->next == NULL)
            return false;
        rabbit = rabbit->next->next;
        turtle = turtle->next;
        if ( turtle == rabbit)
            return true;
    }

    return false;
}
};


/*

Rabbit and Turtle. One day turtle will catch up rabbit!

*/
