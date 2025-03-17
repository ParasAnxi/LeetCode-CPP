class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
        }
        vector<int> v(maxi + 1, 1);
        for (int i = 0; i < n; i++){
            v[nums[i]] = 1 - v[nums[i]];
        }
        for (int i = 0; i < v.size(); i++){
            if (v[i] == 0){
                return false;
            }
        }
        return true;
    }
};