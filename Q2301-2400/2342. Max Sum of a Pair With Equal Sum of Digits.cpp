class Solution
{
public:
    int solve(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int>> pq;
        int ans = -1;
        for (int &i : nums)
        {
            pq[solve(i)].push(i);
        }
        for (auto &i : pq)
        {
            if (i.second.size() > 1)
            {
                int a = i.second.top();
                i.second.pop();
                int b = i.second.top();
                i.second.pop();
                ans = max(ans, a + b);
            }
        }
        return ans;
    }
};