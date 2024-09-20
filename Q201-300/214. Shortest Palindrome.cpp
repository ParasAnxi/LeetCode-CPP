
class Solution
{
private:
    int solve(string &rev,string &s)
    {
        string st = s + '#' + rev;
        int n = st.size();
        vector<int> v(n, 0);

        for (int i = 1; i < n; ++i)
        {
            int j = v[i - 1];
            while (j > 0 && st[i] != st[j])
            {
                j = v[j - 1];
            }
            if (st[i] == st[j])
            {
                j++;
            }
            v[i] = j;
        }

        return v.back();
    }

public:
    string shortestPalindrome(string s)
    {
        string rev_s = string(s.rbegin(), s.rend());
        int c = solve(rev_s, s);
        return rev_s.substr(0, s.length() - c) + s;
    }
};