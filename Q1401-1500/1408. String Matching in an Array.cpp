class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.length() < b.length(); });
        vector<string> ans;
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};