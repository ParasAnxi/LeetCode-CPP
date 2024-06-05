class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        map<pair<char, int>, int> mp;
        vector<int> visit(26, 0);
        for (auto &it : words)
        {
            vector<int> visit(26, 0);
            for (char c : it)
            {
                mp[{c, visit[c - 'a'] + 1}]++;
                visit[c - 'a'] += 1;
            }
        }
        vector<string> ans;
        for (auto it : mp)
        {
            if (it.second % words.size() == 0)
                ans.push_back(string(1, it.first.first));
        }
        return ans;
    }
};