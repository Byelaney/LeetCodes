/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

*/


public class Solution {
	public boolean isPalindrome(String s) {
		s = s.toLowerCase();
        int l = 0, r = s.length()-1;
        while (l < r)
        {
        	while(l<s.length()-1 && (!Character.isLetter(s.charAt(l)) && !Character.isDigit(s.charAt(l)))) l++;
        	while(r>=0 && (!Character.isLetter(s.charAt(r))&& !Character.isDigit(s.charAt(r))))r--;
        	if (l >= r) break;
        	if (s.charAt(l) != s.charAt(r))
        		return false;
        	else
        	{
        		l++;r--;
        	}
        }
        return true;
    }
}
