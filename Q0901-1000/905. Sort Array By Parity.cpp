class Solution
{
private:
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e)
        {
            if (nums[s] & 1)
            {
                swap(nums, s, e);
                e--;
            }
            else
            {
                s++;
            }
        }
        return nums;
    }
};