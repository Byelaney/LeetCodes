/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    bool isPowerOfFour(int num) {
    if (num <= 0) return false;
    if (num == 1) return true;

    int base = 1;
    for (int pow = 2;pow <= 30;pow+=2)
    {
        base = base << 2;
        if ((num | base) == base)
            return true;
    }
    return false;
}
};
