class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long maxi = 0;
        while (k != 0)
        {
            int ele = pq.top();
            pq.pop();

            maxi += ele;

            int val = ceil(ele / 3.0);
            pq.push(val);

            k--;
        }
        return maxi;
    }
};