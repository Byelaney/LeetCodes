/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

public class Solution {
     int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s[]={0,1,2};
        if (n<=2) {return s[n];}
        int j = 2;
        while (true){
            j++;
            s[(j%3)] = s[((j+1)%3)] + s[((j+2)%3)];
            if (j==n) {return s[j%3];}
        }
    }
}
