/*

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    int r = 0, n = (int)nums.size(), i = 0, last = 0;
    vector<int> ret(2, 0);

    for (i = 0; i < n; ++i)
        r ^= nums[i];

    last = r & (~(r - 1));
    for (i = 0; i < n; ++i)
    {
        if ((last & nums[i]) != 0)
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }

    return ret;
}
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    vector<int> v;
    map<int,int> m;
    for(int i = 0;i<nums.size();i++)
    {
        if (m.count(nums[i]) == 1)
        {
            m.erase(nums[i]);
        }
        else
        {
            m[nums[i]] = 1;
        }

    }

    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();++it)
    {
        v.push_back(it->first);
    }

    return v;
}
};


/*

I did not figure out the best method for this problem, I saw this method in forum.
The second method is my solution, about 52ms and the first one 20ms, great solution actually.

1.assume that A and B are the two elements which we want to find;
2.use XOR for all elements,the result is : r = A^B,we just need to distinguish A from B next step;
3.if we can find a bit '1' in r,then the bit in corresponding position in A and B must be different.We can use {last = r & (~(r-1))} to get the last bit 1 int r;
4.we use last to divide all numbers into two groups,then A and B must fall into the two distrinct groups.XOR elements in eash group,get the A and B.

*/
