class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<bool> isPrime(n + 1, true);
        vector<int> ans;
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (!isPrime[i])
                continue;
            ans.push_back(i);
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
        return ans;
    }

    bool primeSubOperation(vector<int> &nums)
    {
        vector<int> primes = sieveOfEratosthenes(*max_element(nums.begin(), nums.end()));
        int prev = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = lower_bound(primes.begin(), primes.end(), nums[i] - prev) - primes.begin();
            if (index == 0)
            {
                if (nums[i] <= prev)
                    return false;
                prev = nums[i];
            }
            else
                prev = nums[i] - primes[index - 1];
        }
        return true;
    }
};