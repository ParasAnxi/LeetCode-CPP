class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        auto cmp = [](pair<char, int> &a, pair<char, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (auto i : freq)
        {
            pq.push(i);
        }

        string ans = "";
        while (!pq.empty())
        {
            pair<char, int> curr = pq.top();
            pq.pop();
            ans += string(curr.second, curr.first);
        }
        return ans;
    }
};