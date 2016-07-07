---
title: divby8
date: 2016-06-07 21:49:11
categories: codeforces
tags: [ACM,brute_force]
mathjax: true
---
## C. Divisibility by Eight

You are given a non-negative integer n, its decimal representation consists of at most 100 digits and doesn't contain leading zeroes.

Your task is to determine if it is possible in this case to remove some of the digits (possibly not remove any digit at all) so that the result contains at least one digit, forms a non-negative integer, doesn't have leading zeroes and is divisible by 8. After the removing, it is forbidden to rearrange the digits.

If a solution exists, you should print it.

Input
The single line of the input contains a non-negative integer n. The representation of number n doesn't contain any leading zeroes and its length doesn't exceed 100 digits.

Output
Print "NO" (without quotes), if there is no such way to remove some digits from number n.

Otherwise, print "YES" in the first line and the resulting number after removing digits from number n in the second line. The printed number must be divisible by 8.

If there are multiple possible answers, you may print any of them.


这里需要用到一个小知识，如果一个数能被8整除的话，那么这个数的最右三位（只有二位或一位的话同理）一定能被8整除。因为输入很大有100位数字，所以使用string来存储。这里我们先构建一个数组，里面存储了所有0到999能被8整除的数字。使用暴力算法，迭代每一个数字去看输入的最右三位是否能被整除。[My AC code](http://codeforces.com/contest/550/submission/18053768)
