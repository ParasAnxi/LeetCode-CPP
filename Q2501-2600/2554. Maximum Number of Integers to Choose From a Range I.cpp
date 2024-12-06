class Solution
{
public:
    int maxCount(vector<int> &banned, int &n, int &maxSum)
    {
        bitset<10001> banInd;
        int count = 0;
        if (maxSum >= (n * (n + 1)) / 2)
        {
            for (count = n; int &num : banned)
            {
                if (num <= n && !banInd[num])
                    count--, banInd.set(num);
            }
            return count;
        }
        for (const int &num : banned)
            banInd.set(num);
        for (int i = 1; i <= n; i++)
        {
            if (banInd[i])
                continue;
            if (i > maxSum)
                return count;
            count++;
            maxSum -= i;
        }
        return count;
    }
};