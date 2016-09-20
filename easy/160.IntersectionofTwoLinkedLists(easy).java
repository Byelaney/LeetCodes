/*

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
   public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if ( headA == null || headB == null) return null;
        int countA = 0,countB = 0;
        ListNode A = headA;
        ListNode B = headB;
        while ( A != null)
        {
            countA++;
            A = A.next;
        }

        while ( B != null)
        {
            countB++;
            B = B.next;
        }
        A = headA;
        B = headB;
        if ( countA > countB )
        {
            for ( int i = 0;i< countA - countB;i++){
                A = A.next;
            }
        }
        else
        {
            for ( int i = 0;i< countB - countA;i++){
                B = B.next;
            }
        }

        ListNode result = null;
        while ( A != null)
        {
            if ( A == B ){
            	result = A;
            	break;
            }
            A = A.next; B = B.next;
        }

        return result;
    }
}
