class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            freq[i]++;
        }
        int ans = 0;
        int maxi = 0;
        for (auto i : freq)
        {
            maxi = max(maxi, i.second);
        }
        for (auto i : freq)
        {
            if (i.second == maxi)
            {
                ans++;
            }
        }
        return maxi * ans;
    }
};