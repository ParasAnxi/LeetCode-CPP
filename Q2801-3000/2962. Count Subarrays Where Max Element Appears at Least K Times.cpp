class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k){
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
        }
        long long ans = 0;
        int s = 0;
        int count = 0;
        for (auto e = 0; e < n; e++)
        {
            if (nums[e] == maxi)
            {
                count++;
            }
            while (count == k)
            {
                if (nums[s] == maxi)
                {
                    count--;
                }
                s++;
            }
            ans += s;
        }
        return ans;
    }
};