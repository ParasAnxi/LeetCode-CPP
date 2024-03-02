class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0, right = n - 1, index = n - 1;

        while (left <= right)
        {
            int leftS = nums[left] * nums[left];
            int rightS = nums[right] * nums[right];

            if (leftS > rightS)
            {
                ans[index] = leftS;
                left++;
            }
            else
            {
                ans[index] = rightS;
                right--;
            }
            index--;
        }
        return ans;
    }
};