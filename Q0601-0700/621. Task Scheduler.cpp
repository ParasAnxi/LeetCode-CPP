class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int m = tasks.size();
        int freq[26] = {0};
        for (auto &task : tasks)
        {
            freq[task - 'A']++;
        }
        int count = 0;
        int max_freq = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > max_freq)
            {
                max_freq = freq[i];
                count = 1;
            }
            else if (freq[i] == max_freq)
            {
                count++;
            }
        }
        return max(m, (max_freq - 1) * (n + 1) + count);
    }
};