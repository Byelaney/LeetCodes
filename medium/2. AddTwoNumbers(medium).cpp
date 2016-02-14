/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if ( l1 != NULL && l2 !=NULL)
    {
        int off_set = 0;
        int sum = l1->val + l2->val;
        if (sum >= 10)
            off_set++;
        ListNode* head = new ListNode(sum%10);
        l1=l1->next;l2=l2->next;

        ListNode* pre = head;
        while (l1!=NULL && l2!=NULL)
        {
            sum = l1->val + l2->val + off_set;
            if ( sum >= 10)
            {
                off_set = 1;
            }
            else
            {
                off_set = 0;
            }

            ListNode* tmp = new ListNode(sum%10);
            pre->next = tmp;
            pre = tmp;

            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 == NULL)
        {
            if (off_set)
            {
                ListNode* tmp = new ListNode(1);
                pre->next = tmp;
                tmp->next = NULL;
            }
        }
        else if (l1 != NULL)
        {
            pre->next = l1;
            if (off_set)
            {
                while (l1 != NULL)
                {
                    sum = l1->val + off_set;
                    if (sum >=10)
                    {
                        l1->val = sum%10;
                        off_set = 1;
                    }
                    else
                    {
                        l1->val = sum;
                        off_set = 0;
                        break;
                    }
                    if (l1->next != NULL)
                        l1 = l1->next;
                    else
                        break;
                }
                if (off_set)
                {
                    ListNode* t = new ListNode(1);
                    t->next = NULL;
                    l1->next = t;
                }
            }
        }
        else
        {   pre->next = l2;
            if (off_set)
            {
                while (l2 != NULL)
                {
                    sum = l2->val + off_set;
                    if (sum >=10)
                    {
                        l2->val = sum%10;
                        off_set = 1;
                    }
                    else
                    {
                        l2->val = sum;
                        off_set = 0;
                        break;
                    }

                    if (l2->next != NULL)
                        l2 = l2->next;
                    else
                        break;
                }
                if (off_set)
                {
                    ListNode* t = new ListNode(1);
                    t->next = NULL;
                    l2->next = t;
                }
            }
        }
        return head;
    }
    else if (l1 == NULL && l2 == NULL)
        return NULL;
    else
        return (l1==NULL)?l2:l1;
}
};



/*

My solution works fine...But it's just too long to go.
The basic algorithm is to use digit plus and offset.

*/
