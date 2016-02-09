/*

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    map<int,int> hm;
    for (int i = 0;i<nums.size();i++)
    {
        if (hm.count(nums[i]) == 0)
        {
            hm[nums[i]] = 1;
        }
        else
            return true;
        
    }
    return false;
}
};



class Solution {
public: bool containsDuplicate(vector<int>& nums) {

    if(nums.size() <= 1) return 0;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 1; ++i){

        if(nums[i] == nums[i+1]) return 1;

    }

    return 0;

}
};


/*

The first time I use the map to solve this problem, but it seems slow.(100ms to beat 5% users).
Then I saw a solution which uses sort() to solve this problem with only 36ms(beat 92% users).

*/
