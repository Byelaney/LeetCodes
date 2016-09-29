/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

*/

class Solution {
public:
    bool isVowel(char c)
{
    if (c == 'a') return true;
    else if (c == 'e') return true;
    else if (c == 'u') return true;
    else if (c == 'i') return true;
    else if (c == 'o') return true;
    else if (c == 'A') return true;
    else if (c == 'E') return true;
    else if (c == 'U') return true;
    else if (c == 'I') return true;
    else if (c == 'O') return true;
    else return false;
}

string reverseVowels(string s) {
    int left = 0;
    int right = (int)s.size()-1;
    while (left < right)
    {
        while (left < right && !isVowel(s[left]))
            left++;
        while (right > left && !isVowel(s[right]))
            right--;

        char c = s[left];
        s[left] = s[right];
        s[right] = c;
        left++;right--;
    }
    return s;
}
};
