/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

*/

class Solution {
public:
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

bool wordPattern(string pattern, string str) {
    vector<string> v = split(str, ' ');
    unordered_map<string, char> ump;
    unordered_map<char, string> ump1;
    if (pattern.size() != v.size()) return false;
    for (int i = 0;i<v.size();++i)
    {
        if (ump.count(v[i]) > 0)
        {
            if (ump[v[i]] != pattern[i]) return false;
        }
        else
            ump[v[i]] = pattern[i];

        if (ump1.count(pattern[i]) > 0)
        {
            if (ump1[pattern[i]] != v[i]) return false;
        }
        else
            ump1[pattern[i]] = v[i];
    }
    return true;
}
};
