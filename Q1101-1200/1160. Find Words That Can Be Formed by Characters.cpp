class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<char> count(26, 0);
        int ans = 0;
        for (char c : chars)
        {
            count[c - 'a']++;
        }
        for (auto word : words)
        {
            vector<char> temp(26, 0);
            for (char c : word)
            {
                temp[c - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++)
            {
                if (count[i] < temp[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans += word.size();
            }
        }
        return ans;
    }
};