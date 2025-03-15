class Solution
{
public:
    void solve(vector<int> &nums, int index, int k, bool steal, vector<int> &ans, int houses, int &capacity){
        if (k < 0 || index < 0)
        {
            if (ans.size() == houses)
            {
                int l_capacity = 0;
                for (auto it : ans)
                {
                    l_capacity = max(it, l_capacity);
                }
                capacity = min(capacity, l_capacity);
            }
            return;
        }
        int take = 0;
        if (steal){
            ans.push_back(nums[index]);
            solve(nums, index - 1, k - 1, false, ans, houses, capacity);
            ans.pop_back();
        }
        solve(nums, index - 1, k, true, ans, houses, capacity);
    }

    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        int capacity = 1e9;
        solve(nums, n - 1, k, true, ans, k, capacity);
        return capacity;
    }
};
class Solution
{
public:
    void solve(vector<int> &nums, int index, int k, bool steal, int &capacity, int last_house)
    {
        if (k == 0)
        {
            capacity = min(capacity, last_house);
            return;
        }
        if (index < 0)
        {
            return;
        }
        if (steal)
        {
            solve(nums, index - 1, k - 1, false, capacity, max(nums[index], last_house));
        }
        solve(nums, index - 1, k, true, capacity, last_house);
    }

    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        int capacity = 1e9;
        solve(nums, n - 1, k, true, capacity, -1e9);
        return capacity;
    }
};
class Solution
{
public:
    int solveMem(vector<int> &nums, int index, int k, vector<vector<int>> &dp)
    {
        if (k == 0)
            return 0;
        if (index < 0)
            return 1e9;

        if (dp[index][k] != -1)
            return dp[index][k];
        int take = max(nums[index], solveMem(nums, index - 2, k - 1, dp));
        int notTake = solveMem(nums, index - 1, k, dp);
        return dp[index][k] = min(take, notTake);
    }

    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solveMem(nums, n - 1, k, dp);
    }
};

class Solution
{
public:
    bool isPossible(vector<int> &nums, int mid, int k){
        int count = 0;
        int n = nums.size();
        int i = 0;
        while (i < n){
            if (nums[i] <= mid){
                count++;
                i += 2;
            }
            else{
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int left = 1e9;
        int right = -1e9;
        for (auto &i : nums)
        {
            left = min(i, left);
            right = max(i, right);
        }
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (isPossible(nums, mid, k)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};