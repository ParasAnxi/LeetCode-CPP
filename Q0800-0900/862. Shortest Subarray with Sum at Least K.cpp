class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int num = INT_MAX;
        long long sum = 0;
        deque<pair<long long, int>> q;
        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            if (sum >= k)
            {
                num = min(num, r + 1);
            }
            while (!q.empty() && sum - q.front().first >= k)
            {
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                num = min(num, r - endIdx);
            }
            while (!q.empty() && q.back().first > sum)
            {
                q.pop_back();
            }
            q.push_back({sum, r});
        }
        return num == INT_MAX ? -1 : num;
    }
};