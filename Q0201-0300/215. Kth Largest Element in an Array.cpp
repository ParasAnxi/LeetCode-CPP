class Solution
{
public:
    int quick_select(vector<int> &nums, int st, int en)
    {
        int i = st - 1, j = st;
        int pi = en;
        while (j < en)
        {
            if (nums[j] < nums[pi])
            {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        swap(nums[j], nums[i + 1]);
        return i + 1;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int st = 0;
        int en = n - 1;
        while (st <= en)
        {
            int a = quick_select(nums, st, en);
            if (a == n - k)
            {
                return nums[a];
            }
            if (a > n - k)
            {
                en = a - 1;
            }
            else
            {
                st = a + 1;
            }
        }
        return 0;
    }
};