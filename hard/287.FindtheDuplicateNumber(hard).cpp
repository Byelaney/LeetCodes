/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int low = 1;
    int high = (int)nums.size()-1;
    int mid = 0;
    int count = 0;
    while (low < high)
    {
        count = 0;
        mid = low + (high - low)/2;
        for (int i = 0;i<nums.size();i++)
        {
            if (nums[i] <= mid)
                count++;
        }

        if (count > mid)
            high = mid;
        else
            low = mid+1;
    }
    return low;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums)
{
    int turtle = 0;
    int hare = 0;

    turtle = nums[turtle];
    hare = nums[nums[hare]];

    while (turtle != hare)
    {
        turtle = nums[turtle];
        hare = nums[nums[hare]];
    }

    hare = 0;
    while (turtle != hare)
    {
        turtle = nums[turtle];
        hare = nums[hare];
    }

    return turtle;
}
};


/*

First time I just want to use a dictionary  to solve this problem.The trick is
that I did not use the 1-n elements efficiently .

Then comes the binary update
solution.If there are n+1 elements with n distinct elements,them there must be
one duplicate element(pigeonhole principle).Since all elements range from 1-n,
then we choose one [mid] element to begin to partition the whole elements.
>= [mid] and < [mid],the duplicate element should appear in the majory group.
We can iterate this till we find the number.

--------------------------------------------------------------------------------

Finally,it comes with the perfect solution.You can check it here
http://keithschwarz.com/interesting/code/?dir=find-duplicate

To understand this,you need to do a little math.
At first you can find it's possible to build a graph with index and value.
index is the vertice and value is the next vertice.Then you can find there always
exist a circle.The duplicate element is the circle entry.
Then randomlly choose a vertice to begin,assume the distance between the start
vertice and circle entry is L.With a circle,we can know turtle and hare
will finally meet at the same vertice.Assume the whole circle length is O and the
turtle position is X far away from circle entry.
Let v[turtle] = 1,v[hare] = 2,
if turtle and hare meets,we must have
S(hare) - S(turtle) = O * n,we need the first meet,so set n = 1
assume time is t,then we have
2t - t = O, t = O
S(turtle) = 1 * O = L + X

the core equality　is O = L + X (*)


Then we let hare return to the start vertice,and set v[hare] = v[turtle] = 1
let's see what will happen if hare arrive at the circle entry.

t' = L/1 = L, S'(turtle) = L * 1 = L
Since turtle was at position X away from the circle entry,now it should be at
L + X away from the circle entry,but we have already known L + X is O!(*)
Now turtle and hare meet at the circle entry!

*/
