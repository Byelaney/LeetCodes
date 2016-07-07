---
title: overloadcpp
date: 2016-06-25 21:34:54
categories: LintCode
tags: operator
---

## 赋值运算符重载

实现赋值运算符重载函数，确保：

新的数据可准确地被复制
旧的数据可准确地删除/释放
可进行 A = B = C 赋值

如果进行 A = B 赋值，则 A 中的数据被删除，取而代之的是 B 中的数据。

如果进行 A = B = C 赋值，则 A 和 B 都复制了 C 中的数据。

```cpp
class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (this == &object)
            return *this;

        if (m_pData)
        {
            delete []m_pData;
            m_pData = NULL;
        }

        if (object.m_pData)
        {
            m_pData = new char[strlen(object.m_pData)+1];
            strcpy(m_pData, object.m_pData);
        }
        return *this;
    }
};
```
