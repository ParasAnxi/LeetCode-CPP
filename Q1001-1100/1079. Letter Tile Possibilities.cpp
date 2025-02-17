class Solution
{
public:
    int solve(int n, vector<int> &freq, int s)
    {
        if (n == 1)
            return s - count(freq.begin(), freq.end(), 0);
        int ans = 0;
        for (int i = 0; i < s; i++)
        {
            if (freq[i] > 0)
            {
                freq[i]--;
                ans += solve(n - 1, freq, s);
                freq[i]++;
            }
        }
        return ans;
    }
    int numTilePossibilities(string &tiles)
    {
        int s = 0, n = tiles.size();
        vector<int> freq(26, 0);
        for (char c : tiles){
            if (++freq[c - 'A'] == 1)
            s++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        freq.resize(s);
        int count = 0;
        for (int i = 1; i <= n; i++)
            count += solve(i, freq, s);

        return count;
    }
};