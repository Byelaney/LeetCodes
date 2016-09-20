/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/

class Solution {
public:
    int firstUniqChar(string s) {
    int a[26];
    for (int i = 0;i<26;++i)
        a[i] = 0;
    
    for (int i = 0;i<s.size();++i)
        a[s[i]-'a']++;

    int min = 2147483647;
    for (int i = 0;i<26;++i)
    {
        if (a[i] == 1)
        {
            char c = 'a' + i;
            int pos = (int)s.find(c);
            if (pos >= 0 && pos < min)
                min = pos;
        }
    }
    if (min == 2147483647) return -1;
    return min;
}
};
