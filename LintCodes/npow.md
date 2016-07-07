---
title: npow
date: 2016-06-12 10:08:19
categories: LintCode
tags: DivideAndConquer
---
##  x的n次幂

实现 pow(x,n),当答案和标准输出差绝对值小于1e-3时都算正确

没什么说的，使用分而治之方法，记得考虑n小于0的情况。

```cpp
double myPow(double x, int n) {
        // Write your code here
    if (n == 0) return 1;
    if (n == 1) return x;

    if (n > 0)
    {
        double t = myPow(x, n/2);
        if (n%2 == 0)
            return t*t;
        else
            return t*t*x;
    }
    else
    {
        n = -n;
        double t = myPow(x, n/2);
        if (n%2 == 0)
            return 1/(t*t);
        else
            return 1/(t*t*x);
    }
    }
```
