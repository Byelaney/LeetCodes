/*

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/

class Solution {
public:
int b2direction(string s, int l, int r, int longest)
{
    int offset = 0;
    while (l>=0 && r <s.size())
    {
        if (s[l] == s[r])
        {
            if (r-l+1 > longest)
                offset = r-l+1;
            l--;r++;
        }
        else
            break;
    }
    return offset;
}

string longestPalindrome(string s)
{
    if (s.size() <= 2) return s;

    int longest = 1;
    int start = 1;
    // left corner case
    if (s[0] == s[1])
        longest = 2;
    // right corner case
    if (s[s.size()-1] == s[s.size()-2])
    {
        longest = 2;
        start = s.size()-1;
    }

    for (int i = 1;i<s.size();++i)
    {
        int l = i-1;
        int r = i+1;
        // odd mode
        int odd = b2direction(s, l, r, longest);
        int even = 1;

        // even mode
        if (s[i] == s[i-1])
        {
            l = i-2;
            r = i+1;
            even = b2direction(s, l, r, longest);
        }

        if (max(odd, even) > longest)
        {
            longest = max(odd, even);
            start = i;
        }
    }
    return s.substr(start-longest/2, longest);
}
};


/*

Solution 2 , DP

*/

class Solution {
public:
    string longestPalindrome(string s) {
    if (s.size() <= 1)
      return s;

    bool dp[s.size()][s.size()];
    int longest = 1;
    int start = 0,end = 0;
    for (int i = 0;i<s.size();++i)
    {
        for (int j = 0;j<s.size();++j)
        {
            if (i>=j)
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }

    for (int len=1;len<s.size();++len)
    {
        for (int i = 0;i+len<s.size();++i)
        {
            int j = i+len;
            if (s[i] != s[j])
                dp[i][j] = false;
            else
            {
                dp[i][j] = dp[i+1][j-1];
                if (dp[i][j])
                {
                    if (j-i+1 > longest)
                    {
                        longest = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
    }
    return s.substr(start, end-start+1);
    }
};
