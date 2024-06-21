class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        vector<int> v(n + 1, 0);
        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            if (grumpy[i - 1] == 1)
            {
                v[i] = v[i - 1] + customers[i - 1];
            }
            else
            {
                v[i] = v[i - 1];
            }
            total += customers[i - 1];
        }
        int i = 1;
        int j = 1;
        int maxi = 0;
        while (j <= n)
        {
            if (j - i + 1 == minutes)
            {
                int sum = v[j] - v[i - 1];
                maxi = max(maxi, sum);
                i++;
            }
            j++;
        }
        return total - v[n] + maxi;
    }
};