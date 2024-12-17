class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            v[s[i] - 'a']++;
        }

        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > 0)
                pq.push({(i + 'a'), v[i]});
        }

        string a = "";
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int use = min(it.second, repeatLimit);
            a.append(use, it.first);
            it.second -= use;

            if (it.second > 0)
            {
                if (pq.empty())
                    break;
                auto it1 = pq.top();
                pq.pop();

                a.push_back(it1.first);
                it1.second -= 1;

                if (it1.second > 0)
                    pq.push({it1.first, it1.second});
                pq.push({it.first, it.second});
            }
        }
        return a;
    }
};