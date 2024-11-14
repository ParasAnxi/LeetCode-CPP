class Solution
{
public:
    bool isPossible(int mid, vector<int> &quantities, int n)
    {
        int ans = 0;
        for (int i = 0; i < quantities.size(); i++)
        {
            ans += (quantities[i] + mid - 1) / mid;
        }
        if (ans <= n)
            return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int ans = INT_MAX;
        int left = 1, right = 1e5;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (isPossible(mid, quantities, n))
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};