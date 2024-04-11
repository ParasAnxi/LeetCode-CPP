class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans;
        int n = num.size() - k;
        for (char digit : num)
        {
            while (k > 0 && !ans.empty() && ans.back() > digit)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(digit);
        }
        ans.resize(n);
        int i = 0;
        while (i < ans.size() && ans[i] == '0')
        {
            i++;
        }
        return i == ans.size() ? "0" : ans.substr(i);
    }
};