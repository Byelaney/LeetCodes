/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* prev = new ListNode(1);
    ListNode* front = head;
    ListNode* back = front->next;
    if (back == NULL) return front;
    head = back;
    while (back != NULL)
    {
        ListNode* tmp = back->next;
        back->next = front;
        front->next = tmp;
        prev->next = back;
        prev = front;
        front = front->next;
        if (front == NULL) break;
        back = front->next;
        if (back == NULL) break;
    }
    return head;
}
};
