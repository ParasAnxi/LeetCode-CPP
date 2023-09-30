class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> s;
        int ele = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < ele)
                return true;
            while (!s.empty() && s.top() < nums[i])
            {
                ele = s.top();
                s.pop();
            }
            s.push(num[i]);
        }
        return false;
    }
};