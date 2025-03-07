class Solution
{
    vector<bool> solve(int n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n + 1; i++)
        {
            if (prime[i])
            {
                for (int j = 2 * i; j < n + 1; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> prime = solve(right);
        vector<int> ans = {-1, -1};
        int first = -1, second = -1;
        int diff = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            if (!prime[i])
                continue;
            if (first == -1)
                first = i;
            else if (second == -1)
            {
                second = i;
                int temp = second - first;
                if (temp < diff)
                {
                    ans[0] = first;
                    ans[1] = second;
                    diff = temp;
                }
                first = second;
                second = -1;
            }
        }
        return ans;
    }
};