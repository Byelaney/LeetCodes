/*

Write a function to find the longest common prefix string amongst an array of strings.

*/

public class Solution {
     public String longestCommonPrefix(String[] strs) {
		    if(strs == null || strs.length == 0)    return "";
		    Arrays.sort(strs);
		    int i = 0;
		    for (;i<Math.min(strs[0].length(), strs[strs.length-1].length());++i)
		    {
		    	if (strs[0].charAt(i) != strs[strs.length-1].charAt(i))
		    		break;
		    }
		    return strs[0].substring(0, i);
		}
}
