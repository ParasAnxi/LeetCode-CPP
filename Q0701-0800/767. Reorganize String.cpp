class Solution
{
public:
    string reorganizeString(string s)
    {
        int len = s.length();
        vector<int> v(26, 0);
        for (auto x : s)
        {
            v[x - 'a']++;
            if (v[x - 'a'] > (len + 1) / 2)
                return "";
        }
        priority_queue<pair<int, char>> pq;
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (v[i - 'a'] > 0)
                pq.emplace(v[i - 'a'], i);
        }
        string ans = "";
        while (pq.size() >= 2)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            p1.first--;
            ans += p2.second;
            p2.first--;
            if (p1.first > 0)
            {
                pq.emplace(p1.first, p1.second);
            }
            if (p2.first > 0)
            {
                pq.emplace(p2.first, p2.second);
            }
        }
        if (!pq.empty())
        {
            auto p3 = pq.top();
            ans += p3.second;
            pq.pop();
        }
        return ans;
    }
};