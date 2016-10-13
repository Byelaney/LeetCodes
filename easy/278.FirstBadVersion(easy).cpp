/*

Total Accepted: 31631 Total Submissions: 144974 Difficulty: Easy
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
{
    int low = 1, high = n, mid;
    mid = 0;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(!isBadVersion(mid))
            low = mid + 1;
        else
        {
            if(mid == 1 || !isBadVersion(mid - 1))
                return mid;
            else
                high = mid - 1;
        }
    }
    return mid;
}
};


/*

The basic method is really simple...Use binary search to find the bad version.
But the implementation is tricky.When you use mid = (low+high)/2 it seems to fail.
The reason could be the input number is so big that the calculation is out of
range.Basically you can use mid = low + (high-low)/2 to substitute it.
This is a kind of math magic.

*/
