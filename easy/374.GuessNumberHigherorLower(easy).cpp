/*

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.

*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
    int start = 1;
    int end = n;
    int middle = ((end-start)>>1)+start;
    while (1)
    {
        middle = ((end-start)>>1) + start;
        if (guess(middle) == -1)
            end = middle - 1;
        else if (guess(middle) == 1)
            start = middle + 1;
        else
            return middle;
    }
}
};
