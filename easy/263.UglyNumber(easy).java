/*

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

*/

public class Solution {
    public boolean isUgly(int num) {
        if (num == 1 ) return true;
        if( num == 0 ) return false;
        int []a = {2,3,5};

        int i = 0;
        int divied = num;
        boolean result = false;
        while (true)
        {
        	if( i>2 )
        		break;

        	if (divied%a[i] == 0)
        	{
        		divied /= a[i];
        		if (divied == 1)
        		{
        			result = true;
        			break;
        		}
        	}

        	else
        	{
        		i++;
        	}

        }

        return result;
    }
}
