class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int maxi = values[0];
        int ans = 0;

        for (int j = 1; j < n; j++)
        {

            int currentScore = maxi + values[j] - j;
            if (currentScore > ans)
            {
                ans = currentScore;
            }

            int curr = values[j] + j;
            if (curr > maxi)
            {
                maxi = curr;
            }
        }
        return ans;
    }
};