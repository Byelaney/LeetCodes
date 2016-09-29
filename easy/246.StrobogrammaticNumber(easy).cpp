/*

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

*/

bool is_map(char a, char b)
{
    if (a == '0' && b == '0')
        return true;
    else if (a == '1' && b == '1')
        return true;
    else if (a == '8' && b == '8')
        return true;
    else if (a == '6' && b == '9')
        return true;
    else if (a == '9' && b == '6')
        return true;
    else
        return false;
}

bool isStrobogrammatic(string num)
{
    if (num.size() == 0) return true;
    int left = 0;
    int right = (int)num.size()-1;

    while (left < right)
    {
        if (!is_map(num[left], num[right]))
            return false;
        left++;
        right--;
    }

    if (left == right)
    {
        if (num[left] == '1' || num[left] == '0' || num[left] == '8')
            return true;
        else
            return false;
    }
    return true;
}
