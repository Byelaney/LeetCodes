/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], counter = 0;
        for (int n: nums) {
        if (counter == 0) {
            candidate = n;
            counter = 1;
        } else if (candidate == n) {
            counter++;
        } else {
            counter--;
        }
    }
    return candidate;
    }
};


/*

This problem is really interesting.At first I use the brute method to solve it.(36ms to beat 40% users)
Then I search for the divide-and-conquer method,it comes with complex.(24ms to beat 52% users)
Finally I see the Moore's voting algorithm.(16ms to beat 84% users)

This algorithm is really fantastic.I try to understand it deeply.
It seems everyone has a vote right.You can vote for yourself or others.Everyone has to
vote in turn(iteration).Since there is only one winner,nums[i] should be compared to this winner(we call
it candidate).There should be three conditions:
(1) Opps,there is no candidate yet,if you vote for someone,let's set him to be the candidate and give
him 1 point!
(2) Yeah,you vote for someone and the guy has already been our candidate!Let's give him one more point!
(3) Oh,no!Your vote target is not our candidate.Then what can we do?We believe more is good.Since your
target has not become the candidate before your vote.We gonna take off one point from the candidate and
let your vote dismiss.

The proof of correctness is really difficult.You can check this http://www.cs.rug.nl/~wim/pub/whh348.pdf

*/
