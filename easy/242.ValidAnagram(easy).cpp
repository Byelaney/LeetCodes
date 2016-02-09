/*

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int  a[26],b[26];
        for(int i = 0;i<26;i++)
        {
            a[i] = 0;
            b[i] = 0;
        }

        for (int i = 0;i<s.size();i++)
        {
            a[s[i] - 'a'] ++;
        }

        for (int i = 0;i<t.size();i++)
        {
            b[t[i] - 'a'] ++;
        }

        for(int i = 0;i<26;i++)
            if (a[i] != b[i])
                return false;

        return true;
}
};


/*

It may make you confused when you do not understand what 'anagram' really means.

*/
