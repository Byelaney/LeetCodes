/*

Reverse a singly linked list.

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
    ListNode* reverseList(ListNode* head) {
    if(head!=NULL)
    {
        ListNode* pre = head;
        ListNode* next = head->next;
        pre->next = NULL;
        ListNode* tmp = NULL;
        while (next != NULL)
        {
            tmp = next->next;
            next->next = pre;
            pre = next;
            next = tmp;
        }

        return pre;
    }
    else
        return NULL;
}
};
