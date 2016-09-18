---
title: Rotate String
categories: programming_snaps
tags: pro_magic
mathjax: true
---

## Rotate String

Given a string and an offset, rotate string by offset. (rotate from left to right)

```cpp
class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
    if (str.size() == 0) return;
    int length = (int)str.size();
    int rs = length - offset%length;
    if (rs == length) return;

    int round = 0;
    for (int i = rs;i<length;++i)
    {
        for (int j = i;j>round;--j)
            swap(str[j], str[j-1]);
        ++round;
    }
}
};

```
