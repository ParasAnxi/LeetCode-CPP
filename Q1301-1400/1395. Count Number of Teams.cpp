class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        vector<int> maxi(rating.size());
        vector<int> mini(rating.size());
        for (int i = 1; i < rating.size() - 1; i++)
        {
            for (int j = i + 1; j < rating.size(); j++)
            {
                if (rating[j] > rating[i])
                {
                    maxi[i]++;
                }
                else
                {
                    mini[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < rating.size() - 2; i++)
        {
            for (int j = i + 1; j < rating.size() - 1; j++)
            {
                if (rating[j] > rating[i])
                {
                    ans += maxi[j];
                }
                else
                {
                    ans += mini[j];
                }
            }
        }
        return ans;
    }
};