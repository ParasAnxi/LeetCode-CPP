class Solution
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < t.size(); i++)
            m[t[i]]++;
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]])
                m[s[i]]--;
        }
        int sum = 0;
        for (auto &i : m)
        {
            sum += i.second;
        }
        return sum;
    }
};