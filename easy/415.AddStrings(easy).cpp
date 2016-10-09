/*

Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class Solution {
public:
    void attach(string& result, string& num1, string& num2, int i, int j, int& offset, int flag)
{
    int val = 0;
    if (flag == 1)
        val = num1[i]-'0' + num2[j]-'0' + offset;
    else if (flag == 2)
        val = num1[i]-'0' + offset;
    else
        val = num2[j]-'0' + offset;

    if (val >= 10)
    {
        offset = 1;
        result.append(to_string(val%10));
    }
    else
    {
        offset = 0;
        result.append(to_string(val));
    }
}

string addStrings(string num1, string num2) {
    string result = "";
    int i = (int)num1.size()-1;
    int j = (int)num2.size()-1;
    int offset = 0;
    while (i>=0 && j>=0)
    {
        attach(result, num1, num2, i, j, offset, 1);
        i--;j--;
    }

    if (num1.size() > num2.size())
    {
        while (i >= 0)
            attach(result, num1, num2, i--, j, offset, 2);
    }
    else
    {
        while (j >= 0)
            attach(result, num1, num2, i, j--, offset, 3);
    }
    if (offset == 1)
        result.append("1");
    reverse(result.begin(), result.end());
    return result;
}
};
