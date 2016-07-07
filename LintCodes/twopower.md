---
title: twopower
date: 2016-06-17 15:16:19
categories: LintCode
tags: Power
---

## O(1)时间检测2的幂次

用 O(1) 时间检测整数 n 是否是 2 的幂次。

对比2的幂次方即可。

```cpp
bool checkPowerOf2(int n) {
    // write your code here
    if (n<0) return false;
    int* bin = new int[32];
    int base = 1;
    for(int i = 0;i<32;++i)
    {
        bin[i] = base;
        base *= 2;
    }
    for(int i = 0;i<32;++i)
    {
        if (n == bin[i])
            return true;
    }
    return false;
}
```
