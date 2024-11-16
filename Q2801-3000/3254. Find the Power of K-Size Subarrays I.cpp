class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++)
        {
            int flag = 0;
            int maxi = 0;
            for (int j = i; j < i + k; j++)
            {
                if (j != i + k - 1 && nums[j] + 1 == nums[j + 1])
                {
                    maxi = max(maxi, nums[j]);
                }
                else if (j != i + k - 1)
                {
                    flag = 1;
                    break;
                }
                else if (j == i + k - 1)
                {
                    maxi = max(maxi, nums[j]);
                }
            }
            if (!flag)
                ans.push_back(maxi);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};