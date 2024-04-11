class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ans(n);
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push_back(i);
        }
        for (auto i : deck)
        {
            ans[q.front()] = i;
            q.pop_front();
            if (!q.empty())
            {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        return ans;
    }
};