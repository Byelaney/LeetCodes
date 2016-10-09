/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    int increment(int ary[], int i, bool& odd)
{
    if (ary[i]%2 == 0)
        return ary[i];
    else
    {
        odd = true;
        return ary[i]/2 * 2;
    }
}

int longestPalindrome(string s) {
    int length = 0;
    bool odd = false;
    int lower[26],upper[26];
    for (int i = 0;i<26;++i)
    {
        lower[i] = 0;
        upper[i] = 0;
    }
    for (int k = 0;k<s.size();++k)
    {
        if (s[k] > 96)
            lower[s[k]-'a']++;
        else
            upper[s[k]-'A']++;
    }

    for (int i = 0;i<26;++i)
    {
        length += increment(lower, i, odd);
        length += increment(upper, i, odd);
    }
    if (odd)
        return length + 1;
    else
        return length;
}
};
