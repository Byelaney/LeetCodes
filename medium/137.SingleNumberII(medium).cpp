/*

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

public class Solution {
    public int singleNumber(int[] nums) {
        int single = 0;
        int bit = 0;
        int c = 0;
        for ( int i = 0;i<32;i++)
        {
            bit = 1 << i;
            c = 0;
            for ( int j = 0;j<nums.length;j++)
            {
                if ( (nums[j]&bit) != 0) c++;
            }

            if ( c%3 != 0 ) single |= bit;

        }

        return single;
    }
}
