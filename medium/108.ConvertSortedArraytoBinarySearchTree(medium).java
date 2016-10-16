/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode recBuild(int start, int end, int nums[])
	  {
		  if (start > end) return null;
		  int mid = (end-start)/2 + start;
		  TreeNode root = new TreeNode(nums[mid]);
		  root.left = recBuild(start, mid-1, nums);
		  root.right = recBuild(mid+1, end, nums);
		  return root;
	  }

	  public TreeNode sortedArrayToBST(int[] nums) {
		  return recBuild(0, nums.length-1, nums);
	  }
}
