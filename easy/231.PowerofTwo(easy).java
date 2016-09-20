/*

Given an integer, write a function to determine if it is a power of two.

*/


public class Solution {
    	public boolean isPowerOfTwo(int n) {
		if ( n == 0 ) return false;
		if ( n == 1 ) return true;

		int remain = n;
		boolean result = false;
		while(true)
		{
			if (remain%2==0)
			{
				remain = remain >> 1;
				if(remain == 1)
				{
					result = true;
					break;
				}
			}
			else
				break;
		}

		return result;
    }
}
