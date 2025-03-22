class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        double sum = 0;
        double result = INT_MAX;
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++)
        {
            ratio.push_back({wage[i] / (double)quality[i], quality[i]});
        }
        sort(ratio.begin(), ratio.end());
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(ratio[i].second);
            sum += ratio[i].second;
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                result = min(result, sum * ratio[i].first);
            }
        }
        return result;
    }
};