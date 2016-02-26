/**

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

**/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    if (digits[digits.size()-1] == 9)
    {
        bool offset = true;
        int p = (int)digits.size()-2;
        while (offset && p>-1)
        {
            if (digits[p] != 9)
            {
                offset = false;
                break;
            }
            p--;
        }
        if (p==-1)
        {
            res.push_back(1);
            for(int i =0;i<digits.size();i++)
                res.push_back(0);
        }
        else
        {
            for(int i =0;i<p;i++)
                res.push_back(digits[i]);
            res.push_back(digits[p]+1);
            for(int i =p+1;i<digits.size();i++)
                res.push_back(0);
        }
    }
    else
    {
        for(int i =0;i<digits.size()-1;i++)
            res.push_back(digits[i]);
        res.push_back(digits[digits.size()-1]+1);
    }
    return res;
}
};
