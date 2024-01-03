class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        int m = bank[0].size();
        int prev = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            for (int j = 0; j < m; j++)
            {
                if (bank[i][j] == '1')
                    curr++;
            }
            if (prev == 0)
            {
                prev = curr;
                curr = 0;
            }
            if (curr != 0)
            {
                sum += (prev * curr);
                prev = curr;
                curr = 0;
            }
        }
        return sum;
    }
};