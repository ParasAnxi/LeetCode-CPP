class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<size_t, vector<size_t>, greater<size_t>> pq;
        for (auto &i : nums)
            pq.push(i);

        int ans = 0;
        while (pq.size() > 1)
        {
            size_t top = pq.top();
            pq.pop();
            if (top >= k)
                return ans;
            else
            {
                size_t sTop = pq.top();
                pq.pop();
                pq.push(min(top, sTop) * 2 + max(top, sTop));
                ans++;
            }
        }

        return ans;
    }
};