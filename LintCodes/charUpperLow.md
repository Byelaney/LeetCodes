---
title: charUpperLow
date: 2016-06-18 00:05:59
categories: LintCode
tags: Pointers
---

## 字符大小写排序

给定一个只包含字母的字符串，按照先小写字母后大写字母的顺序进行排序。小写字母或者大写字母他们之间不一定要保持在原始字符串中的相对位置。

还是很基础的题目,开头和结尾两个指针即可搞定。

```cpp
void sortLetters(string &letters) {
    // write your code here
    int left = 0;
    int right = (int)letters.size() - 1;
    while (left < right)
    {
        while (letters[left] > 96)
            ++left;

        while (letters[right] < 97)
            --right;

        if (left < right)
        {
            if (left < letters.size() && right >= 0)
            {
                // swap them pls
                char tmp = letters[left];
                letters[left] = letters[right];
                letters[right] = tmp;
            }
        }
    }
}
```
