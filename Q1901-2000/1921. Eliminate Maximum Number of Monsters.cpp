class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<float> time(n);
        for (int i = 0; i < n; ++i)
            time[i] = (float)dist[i] / speed[i];
        sort(time.begin(), time.end());
        int ans = 0, i = 0, t = 0;
        while (i < n && t < time[i])
            ans++, t++, i++;
        return ans;
    }
};