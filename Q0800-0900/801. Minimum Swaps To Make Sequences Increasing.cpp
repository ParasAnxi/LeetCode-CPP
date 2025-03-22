class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
    {
        if (index == nums1.size())
        {
            return 0;
        }
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        if (swapped == 1)
        {
            swap(prev1, prev2);
        }
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = solve(nums1, nums2, index + 1, 0);
        }
        if (nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));
        }
        return ans;
    }
    int mem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
    {
        if (index == nums1.size())
        {
            return 0;
        }
        if (dp[index][swapped] != -1)
            return dp[index][swapped];
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        if (swapped == 1)
        {
            swap(prev1, prev2);
        }
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = mem(nums1, nums2, index + 1, 0, dp);
        }
        if (nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + mem(nums1, nums2, index + 1, 1, dp));
        }
        return dp[index][swapped] = ans;
    }
    int tab(vector<int> &nums1, vector<int> &nums2)
    {
        // int n = nums1.size();
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
        for (int index = nums1.size() - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                if (swapped == 1)
                {
                    swap(prev1, prev2);
                }
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = dp[index + 1][0];
                }
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + dp[index + 1][1]);
                }
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int so(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int swapp = 0;
        int noSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;
        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                if (swapped == 1)
                {
                    swap(prev1, prev2);
                }
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = noSwap;
                }
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + swapp);
                }
                if (swapped)
                {
                    currSwap = ans;
                }
                else
                {
                    currNoSwap = ans;
                }
            }
            swapp = currSwap;
            noSwap = currNoSwap;
        }
        return min(swapp, noSwap);
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swapped = 0;
        // return solve(nums1,nums2,1,swapped);
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));
        // return mem(nums1,nums2,1,swapped,dp);
        return so(nums1, nums2);
    }
};