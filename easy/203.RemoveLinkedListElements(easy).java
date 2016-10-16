/*

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
	        if (head == null) return head;
		  	ListNode dummy = new ListNode(0);
	        ListNode prev = dummy;
	        ListNode cur = head;
	        prev.next = cur;
	        while (cur != null)
	        {
	        	if (cur.val != val)
	        		prev = cur;
	        	else
	        		prev.next = cur.next;
	        	cur = cur.next;
	        }
	        return dummy.next;
	  }
}
