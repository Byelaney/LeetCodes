/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode* p = NULL;
    if (l1 != NULL && l2 != NULL)
    {
        head = (ListNode*)malloc(sizeof(struct ListNode));
        p = head;
        head->val = (l1->val<l2->val)?l1->val:l2->val;
        if (l1->val<l2->val)
            l1 = l1->next;
        else
            l2 = l2->next;
    }
    else
    {
        head = (l1==NULL)?l2:l1;
        return head;
    }
    while (l1 != NULL && l2 != NULL)
    {
        ListNode* tmp = (ListNode*)malloc(sizeof(struct ListNode));
        if ( l1->val < l2->val)
        {
            tmp->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            tmp->val = l2->val;
            l2 = l2->next;
        }
        p->next = tmp;
        p = p->next;
    }
    if (l1 != NULL)
        p->next = l1;
    if (l2 != NULL)
        p->next = l2;
    return head;
}
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
