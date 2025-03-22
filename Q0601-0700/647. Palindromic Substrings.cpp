class Solution
{
public:
    int solve(string &s)
    {
        string T = "^#";
        for (auto i : s)
        {
            T += i;
            T += '#';
        }
        int n = T.length();
        vector<int> P(n, 0);
        int c = 0, r = 0;
        int count = 0;

        for (int i = 1; i < n - 1; i++)
        {
            P[i] = (r > i) ? min(r - i, P[2 * c - i]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            {
                P[i]++;
            }
            if (i + P[i] > r)
            {
                c = i;
                r = i + P[i];
            }
            count += (P[i] + 1) / 2;
        }
        return count;
    }
    int countSubstrings(string s)
    {
        return solve(s);
    }
};