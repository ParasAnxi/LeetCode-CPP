class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int s = 1, e = nums.size() - 1, c;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            c = 0;
            for (int n : nums)
            {
                ++c;
            }
            if (c <= mid)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
};