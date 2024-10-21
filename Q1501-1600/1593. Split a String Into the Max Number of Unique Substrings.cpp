class Solution
{
public:
    void solve(string s, int index, int curr, int &maxi, set<string> &st)
    {
        int n = s.size();
        if (curr + (n - index) <= maxi)
            return;
        if (index >= n)
        {
            maxi = max(maxi, curr);
            return;
        }

        for (int j = index; j < n; j++)
        {
            string temp = s.substr(index, j - index + 1);
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                solve(s, j + 1, curr + 1, maxi, st);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s)
    {
        set<string> st;
        int maxi = 0;
        solve(s, 0, 0, maxi, st);
        return maxi;
    }
};