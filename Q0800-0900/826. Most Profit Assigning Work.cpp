class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        sort(worker.begin(), worker.end());
        reverse(worker.begin(), worker.end());
        int n = profit.size();

        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            q.push({profit[i], difficulty[i]});
        }

        int i = 0;
        int ans = 0;
        while (i < worker.size() && !q.empty())
        {
            auto node = q.top();
            if (worker[i] < node.second)
                q.pop();
            else
            {
                ans += node.first;
                i++;
            }
        }
        return ans;
    }
};