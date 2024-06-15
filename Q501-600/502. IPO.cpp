class Solution {
public:

    static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
        return p2.second > p1.second;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int, int>> v;
        int N = profits.size();
        for(int i = 0; i < N; i++) {
            v.push_back({profits[i], capital[i]});
        }
        sort(v.begin(), v.end(), cmp);
        
        priority_queue<int> pq;
        int i = 0;
        k = min(k, N);

        while(k--)
        {
            while (v[i].second <= w && i < N) {
                pq.push(v[i].first);
                i++;
            }
            
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {

        vector<pair<int, int>> v;
        for (int i = 0; i < capital.size(); i++)
        {
            v.push_back({profits[i], capital[i]});
        }
        sort(v.begin(), v.end(), [](const auto &a, const auto &b)
             {
            if (a.second < b.second) return true;
            if (a.second == b.second) return a.first < b.first;
            return false; });
        priority_queue<pair<int, int>> pq;
        for (int i = 0; (i < v.size()) && (k > 0); i++)
        {
            while (w < v[i].second && k > 0 && !pq.empty())
            {
                w += pq.top().first;
                pq.pop();
                k--;
            }
            if (w < v[i].second)
                break;
            pq.push(v[i]);
        }
        while (k > 0 && !pq.empty())
        {
            w += pq.top().first;
            k--;
            pq.pop();
        }
        return w;
    }
};