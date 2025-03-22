class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> maxFreq(26, 0);

        for (const string &word : words2)
        {
            vector<int> freq(26, 0);
            for (char c : word)
            {
                freq[c - 'a']++;
            }

            for (int i = 0; i < 26; ++i)
            {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> ans;

        for (const string &word : words1)
        {
            vector<int> freq(26, 0);
            for (char c : word)
            {
                freq[c - 'a']++;
            }

            bool flag = true;
            for (int i = 0; i < 26; ++i)
            {
                if (freq[i] < maxFreq[i])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                ans.push_back(word);
            }
        }

        return ans;
    }
};