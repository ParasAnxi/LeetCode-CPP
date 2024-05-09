class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long diff = 0;
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - diff > 0)
                ans += (happiness[i] - diff);
            diff++;
        }
        return ans;
    }
};