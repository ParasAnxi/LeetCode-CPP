class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = str.length();
        int ans = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[str[i] - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int cnt = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (freq[i] == 0)
                break;
            ans += (freq[i] * ((cnt / 8) + 1));
            cnt++;
        }
        return ans;
    }
};