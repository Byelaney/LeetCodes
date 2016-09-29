/*

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

*/

class Solution {
public:
    int integerReplacement(int n) {
    unsigned num = n;
    if (num==1) return 0;
    if (num==2) return 1;
    if (num==3) return 2;

    if (num%2 == 0) return 1 + integerReplacement(num/2);
    else
        return 1 + min(integerReplacement(num+1),integerReplacement(num-1));
}
};
