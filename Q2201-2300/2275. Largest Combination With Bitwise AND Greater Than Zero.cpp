class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int it = 0;
        int n = candidates.size();
        int maxi = 0;
        while (it < 32)
        {
            int curr = 0;
            int ex = 0;
            for (auto &candidate : candidates)
            {
                if (candidate == 0)
                {
                    ex++;
                    continue;
                }
                int lBit = candidate & 1;
                if (lBit == 1)
                    curr++;
                candidate = candidate >> 1;
            }
            if (ex == n)
                break;
            maxi = max(maxi, curr);
            it++;
        }
        return maxi;
    }
};