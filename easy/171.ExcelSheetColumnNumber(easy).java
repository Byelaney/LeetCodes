/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28

*/

public class Solution {
    public int titleToNumber(String s)
	{
		int sum = 0;
        int tmp = 0;
        for (int i = 0; i < s.length(); ++i) {
            tmp = s.charAt(i) - 'A' + 1;
            sum = 26 * sum + tmp;  
        }
        return sum;
    }
}
