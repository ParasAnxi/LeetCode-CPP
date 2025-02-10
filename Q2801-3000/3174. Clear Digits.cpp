class Solution
{
public:
    string clearDigits(string s)
    {
        int n = s.size();
        string ans = "";
        for (auto &x : s)
        {
            if (isdigit(x))
            {
                if (!ans.empty())
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans += x;
            }
        }
        return ans;
    }
};