/*

Given  an arbitrary  ransom  note  string and another string containing letters from  all the magazines,  write a function that will return true if the ransom  note can be constructed from the magazines ; otherwise, it will return false.  

Each letter  in  the  magazine string can  only be  used once  in  your ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    if (magazine.size() < ransomNote.size()) return false;
    unordered_map<char, int> ump;
    for (int i = 0;i<ransomNote.size();++i)
    {
        if (ump.count(ransomNote[i]) > 0)
            ump[ransomNote[i]]++;
        else
            ump[ransomNote[i]] = 1;
    }

    for (int i = 0;i<magazine.size();++i)
    {
        if (ump.count(magazine[i]) > 0)
        {
            if (ump[magazine[i]] == 1)
                ump.erase(magazine[i]);
            else if (ump[magazine[i]] > 1)
                ump[magazine[i]]--;
        }
    }
    return (ump.size() == 0);
}
};
