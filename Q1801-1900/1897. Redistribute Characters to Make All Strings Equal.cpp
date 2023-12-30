class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        if (n == 1)
            return true;
        int count[26] = {0};
        for (auto s : words)
        {
            for (char c : s)
                count[c - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            int cnt = count[i];
            if (cnt % n != 0)
                return false;
        }
        return true;
    }
};