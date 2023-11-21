class Solution
{
public:
    int mod = 1000000007;
    int reverse(int n)
    {
        int num = 0;
        while (n > 0)
        {
            num = num * 10;
            num = num + n % 10;
            n /= 10;
        }
        return num;
    }
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<long long, vector<long long>> mp;
        long long count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long sum = (nums[i] - reverse(nums[i])) % mod;
            mp[sum].push_back(i);
        }
        for (auto it : mp)
        {
            long long n = it.second.size();
            count = (count + ((n * (n - 1) / 2) % mod)) % mod;
        }
        return count;
    }
};