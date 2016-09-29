/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
public:
    int get_digit_sum(int n)
{
    int sum = 0;
    vector<int> v;
    while (n)
    {
        v.push_back(n%10);
        n /= 10;
    }
    for (int i = 0;i<v.size();++i)
        sum += v[i]*v[i];
    return sum;
}

bool isHappy(int n) {
    if (n == 1 )return true;
    unordered_set<int> unset;
    while(1)
    {
        int sum = get_digit_sum(n);
        if (sum == 1) return true;

        if (unset.count(sum) > 0) return false;
        else
        {
            n = sum;
            unset.insert(sum);
        }

    }
}
};
