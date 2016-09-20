/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

public class Solution {
     public int uniquePaths(int m, int n) {
	    if (m == 0 || n == 0) return 0;

   int x = Math.min(m, n), y = Math.max(m, n);
   double count = 1;
   for (int i=1; i<x; ++i) {
     count *= (y + i - 1);
     count /= i;
   }

   return (int)count;
	    }


}
