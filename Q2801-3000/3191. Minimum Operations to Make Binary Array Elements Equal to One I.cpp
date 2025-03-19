class Solution
{
public:
    bool solve(vector<int> &nums, int s)
    {
        if (s + 3 > nums.size()){
            return false;
        }
        for (int i = s; i < s + 3; ++i){
            nums[i] ^= 1;
        }
        return true;
    }

    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                if (!solve(nums, i)){
                    return -1;
                }
                ans++;
            }
        }

        return ans;
    }
};