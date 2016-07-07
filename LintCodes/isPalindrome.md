---
title: isPalindrome
date: 2016-06-20 15:05:07
categories: LintCode
tags: Pointer
---

## 有效回文串

给定一个字符串，判断其是否为一个回文串。只包含字母和数字，忽略大小写。

基础题,双指针搞定。

```cpp
bool isvalid(char c)
{
    if (c >= 48 && c <= 57) return true;
    if (c >=65 && c <= 90) return true;
    if (c >= 97 && c <= 122) return true;
    return false;
}

bool isPalindrome(string& s) {
    // Write your code here
    int p1 = 0;
    int p2 = (int)s.size()-1;
    while (p1 < p2)
    {
        while (!isvalid(s[p1]))
            ++p1;
        while (!isvalid(s[p2]))
            --p2;

        if (p1 < p2)
        {
            if (p1 < s.size() && p2 >= 0)
            {
                if (s[p1] == s[p2] || abs(s[p1]-s[p2]) == 32)
                {
                    ++p1;--p2;
                }
                else
                    return false;
            }
        }
    }
    return true;
}
```
