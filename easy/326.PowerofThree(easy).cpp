/*

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

*/


class Solution {
public:
    bool isPowerOfThree(int n)
{
    if (n == 1)
        return true;

    while (n > 2)
    {
        if (n % 3 == 0)
            n/= 3;
        else
            return false;
    }
    return n == 1;
}
};


class Solution {
public:
    bool isPowerOfThree(int n)
{
    return n > 0 && (1162261467 % n == 0);
}
};


/**

The second solution is really tricky....

**/
