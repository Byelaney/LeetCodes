/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
    stack<char> stc;
    char c;
    for (int i = 0;i<s.size();++i)
    {
        if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            stc.push(s[i]);
        else if (s[i] == ')')
        {
            if (stc.size() == 0) return false;
            c = stc.top();
            if (c == '(')
                stc.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (stc.size() == 0) return false;
            c = stc.top();
            if (c == '[')
                stc.pop();
            else
                return false;
        }
        else
        {
            if (stc.size() == 0) return false;
            c = stc.top();
            if (c == '{')
                stc.pop();
            else
                return false;
        }
    }
    if (stc.size() == 0) return true;
    else return false;
}
};
