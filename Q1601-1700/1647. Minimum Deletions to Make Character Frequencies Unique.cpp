class Solution
{
public:
    int minDeletions(string s)
    {
        int ans;
        ans = 0;
        vector<int> freq(26);
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            int j = i + 1;
            sort(freq.rbegin(), freq.rend());
            if (freq[i] <= 0)
            {
                break;
            }
            while (j < 26 && freq[i] == freq[j])
            {
                if (j - i > freq[j])
                {
                    ans += freq[j];
                    freq[j] = 0;
                }
                else
                {
                    ans += j - i;
                    freq[j] -= j - i;
                }
                j++;
            }
        }
        return ans;
    }
};