/*

Given a string, determine if a permutation of the string could form a palindrome.

For example, "code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice? Count the frequency of each character. If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

*/

bool canPermutePalindrome(string s)
{
    int occur[26];
    for (int i = 0;i<26;++i)
        occur[i] = 0;

    locale loc;
    for (int i = 0;i<s.size();++i)
       occur[tolower(s[i],loc) - 'a'] += 1;

    if (s.size() % 2 == 0)
    {
        for (int i = 0;i<26;++i)
        {
            if (occur[i]%2 == 1)
                return false;
        }
        return true;
    }
    else
    {
        int odd_num = 0;
        for (int i = 0;i<26;++i)
        {
            if (occur[i]%2 == 1)
                odd_num++;
        }
        if (odd_num > 1)
            return false;
        else
            return true;
    }
}
