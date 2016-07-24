---
title: generateParenthesis
date: 2016-07-24 15:02:11
categories: LintCode
tags: recursion
---

## 生成括号

给定 n 对括号，请写一个函数以将其生成新的括号组合，并返回所有组合结果。

给定 n = 3, 可生成的组合如下:

"((()))", "(()())", "(())()", "()(())", "()()()"

我的解法没有那么优雅但是ac了，在每个 '(' 的后面添加 '()'。

```cpp
string parenthesis_j(string s,int j)
{
    string res = "";
    int left = 0;
    for (int i = 0;i<s.size();++i)
    {
        if (s[i] != '(')
            res += s[i];
        else
        {
            ++left;
            if (left == j)
            {
                res = res + "(()";
                for (int j = i+1;j<s.size();++j)
                    res += s[j];
                break;
            }
            else
                res += '(';
        }
    }
    return res;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n == 1)
    {
        res.push_back("()");
        return res;
    }

    vector<string> resp = generateParenthesis(n-1);
    set<string> s;
    for (int i = 0;i<resp.size();++i)
    {
        string s1 = "()" + resp[i];
        string s2 = resp[i] + "()";

        s.insert(s1);
        s.insert(s2);

        for (int j = 1;j<n;++j)
        {
            string p = parenthesis_j(resp[i], j);
            s.insert(p);
        }
    }

    for (set<string>::iterator it = s.begin();it != s.end();++it)
        res.push_back(*it);

    return res;
}
```
