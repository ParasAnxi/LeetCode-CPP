class Solution
{
public:
    int check(string s)
    {
        int n = s.length();
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
            (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u'))
        {
            return 1;
        }
        return 0;
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++)
        {
            int val = check(words[i]);
            if (i == 0)
            {
                v[i] = val;
            }
            else
            {
                v[i] = v[i - 1] + val;
            }
        }

        vector<int> ans;
        for (const auto &query : queries)
        {
            int k = query[0];
            int j = query[1];

            int h;
            if (k > 0)
            {
                h = v[j] - v[k - 1];
            }
            else
            {
                h = v[j];
            }

            ans.push_back(h);
        }

        return ans;
    }
};