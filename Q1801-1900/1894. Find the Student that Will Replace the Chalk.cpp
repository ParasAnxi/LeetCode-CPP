class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        long long sum = 0;

        for (int i : chalk)
        {
            sum += i;
        }

        k = k % sum;

        int i = 0;
        while (k >= chalk[i % n])
        {
            k = k - chalk[i % n];
            i++;
        }

        return i % n;
    }
};