class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});
        while (!pq.empty())
        {
            auto [count1, char1] = pq.top();
            pq.pop();
            if (ans.size() >= 2 && ans.back() == char1 && ans[ans.size() - 2] == char1)
            {
                if (pq.empty())
                    break;
                auto [count2, char2] = pq.top();
                pq.pop();
                ans += char2;
                if (--count2 > 0)
                {
                    pq.push({count2, char2});
                }
                pq.push({count1, char1});
            }
            else
            {
                ans += char1;
                if (--count1 > 0)
                {
                    pq.push({count1, char1});
                }
            }
        }
        return ans;
    }
};