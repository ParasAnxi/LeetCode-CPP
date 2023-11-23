class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int s, e, diff, dec;
        vector<int> temp;
        vector<bool> ans;

        for (int i = 0; i < l.size(); ++i)
        {
            dec = 0;
            s = l[i];
            e = r[i];

            for (int j = s; j <= e; ++j)
                temp.push_back(nums[j]);

            sort(temp.begin(), temp.end());
            diff = temp[1] - temp[0];

            for (int j = 1; j < temp.size() - 1; ++j)
            {
                if (temp[j + 1] - temp[j] != diff)
                {
                    ans.push_back(false);
                    dec = 1;
                    break;
                }
            }

            if (dec == 0)
                ans.push_back(true);
            temp.clear();
        }

        return ans;
    }
};