/*

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/

class Solution:
    # @return an integer
    def reverse(self, x):
        temp = 0
        if x > 0 :
            sign = 0
            temp = x
        else:
            sign = 1
            temp = -x
        result = 0
        while temp > 0:
            result = result * 10 + temp % 10
            temp /= 10
        if sign:
            return -result
        else:
            return result
