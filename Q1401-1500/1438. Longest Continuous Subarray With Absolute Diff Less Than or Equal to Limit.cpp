class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int ans = 0;
        multiset<int> st;
        int left = 0, right = 0, n = nums.size();
        while (right < n)
        {
            while (st.empty() || (right < n && *st.rbegin() - *st.begin() <= limit))
            {
                st.insert(nums[right++]);
            }
            ans = max({ans, int(st.size()) - 1});
            while (!st.empty() && left < n && *st.rbegin() - *st.begin() > limit)
            {
                st.erase(st.find(nums[left++]));
            }
            ans = max({ans, int(st.size())});
        }
        return ans;
    }
};