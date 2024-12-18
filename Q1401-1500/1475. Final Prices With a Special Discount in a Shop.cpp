class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> ans(prices);
        stack<int> s;
        s.push(prices[prices.size() - 1]);
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            while (s.size() != 0 && s.top() > prices[i])
            {
                s.pop();
            }
            ans[i] -= s.size() ? s.top() : 0;
            s.push(prices[i]);
        }
        return ans;
    }
};