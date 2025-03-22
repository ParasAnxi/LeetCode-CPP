class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy)
    {
        int n = prices.size();
        if (index == n)
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[index] + solve(prices, index + 1, 0), solve(prices, index + 1, 1));
        }
        else
        {
            profit = max(prices[index] + solve(prices, index + 1, 1), solve(prices, index + 1, 0));
        }
        return profit;
    }
    int mem(vector<int> &prices, int index, int buy, vector<vector<int>> &dp)
    {
        int n = prices.size();
        if (index == n)
        {
            return 0;
        }
        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[index] + mem(prices, index + 1, 0, dp), mem(prices, index + 1, 1, dp));
        }
        else
        {
            profit = max(prices[index] + mem(prices, index + 1, 1, dp), mem(prices, index + 1, 0, dp));
        }
        return dp[index][buy] = profit;
    }
    int tab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                }
                else
                {
                    profit = max(prices[index] + dp[index + 1][1], dp[index + 1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int so(vector<int> &prices)
    {
        int n = prices.size();
        int next0 = 0;
        int next1 = 0;
        int curr0 = 0;
        int curr1 = 0;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    curr1 = max(-prices[index] + next0, next1);
                }
                else
                {
                    curr0 = max(prices[index] + next1, next0);
                }
            }
            next0 = curr0;
            next1 = curr1;
        }
        return next1;
    }
    int maxProfit(vector<int> &prices)
    {
        // return solve(prices,0,1);
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return so(prices);
    }
};