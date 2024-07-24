class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> mp(n);

        for (int i = 0; i < n; ++i)
        {
            string st = to_string(nums[i]);
            string str = st;

            for (char &ch : str)
            {
                ch = '0' + mapping[ch - '0'];
            }
            int num = stoi(str);
            mp[i] = {num, nums[i]};
        }
        sort(mp.begin(), mp.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.first < b.first; });

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = mp[i].second;
        }

        return ans;
    }
};