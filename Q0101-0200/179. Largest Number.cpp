class Solution
{
public:
    static bool comp(string s1, string s2)
    {
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int> &nums)
    {
        string ans;
        vector<string> v;
        for (auto &i : nums)
        {
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end(), comp);
        for (auto &i : v)
        {
            ans += i;
        }
        while (ans.size() > 1 && ans.front() == '0')
        {
            ans.erase(ans.begin());
        }
        return ans;
    }
};