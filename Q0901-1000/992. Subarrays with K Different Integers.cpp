class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        int left = 0;
        int right = 0;
        while (right < nums.size()){
            mp[nums[right]] = right;

            while (mp.size() > k){
                if (mp[nums[left]] == left)
                    mp.erase(nums[left]);
                left++;
            }
            if (mp.size() == k){
                int mini = right;
                for (auto i : mp) mini = min(mini, i.second);
                ans += mini - left + 1;
            }
            right++;
        }
        return ans;
    }
};
