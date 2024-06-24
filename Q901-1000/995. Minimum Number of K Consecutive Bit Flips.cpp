class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int i = 0;
        int j = k - 1;
        int n = nums.size();
        int count = 0;
        queue<int> q;
        while (j < n)
        {
            if (!q.empty() && i - q.front() >= k)
                q.pop();

            if ((q.empty() && nums[i] == 0) || (!q.empty() && ((nums[i] == 0 && q.size() % 2 == 0) || (nums[i] == 1 && q.size() % 2 != 0))))
            {
                q.push(i);
                count++;
            }
            i++;
            j++;
        }
        while (i < n)
        {
            if (!q.empty() && i - q.front() >= k)
                q.pop();
            if ((q.empty() && nums[i] == 0) || (!q.empty() && ((nums[i] == 0 && q.size() % 2 == 0) || (nums[i] == 1 && q.size() % 2 != 0))))
                return -1;
            i++;
        }
        return count;
    }
};