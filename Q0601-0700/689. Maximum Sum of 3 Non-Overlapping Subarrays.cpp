class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        vector<int> leftInd(n, 0);
        int leftSum = prefixSum[k] - prefixSum[0];
        for (int i = k; i < n; i++)
        {
            int currSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (currSum > leftSum)
            {
                leftSum = currSum;
                leftInd[i] = i - k + 1;
            }
            else
            {
                leftInd[i] = leftInd[i - 1];
            }
        }
        vector<int> rightInd(n, 0);
        int rightSum = prefixSum[n] - prefixSum[n - k];
        rightInd[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--)
        {
            int currSum = prefixSum[i + k] - prefixSum[i];
            if (currSum >= rightSum)
            {
                rightSum = currSum;
                rightInd[i] = i;
            }
            else
            {
                rightInd[i] = rightInd[i + 1];
            }
        }
        vector<int> ans(3, 0);
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++)
        {
            int left = leftInd[i - 1];
            int right = rightInd[i + k];
            int currSum = (prefixSum[left + k] - prefixSum[left]) +
                             (prefixSum[i + k] - prefixSum[i]) +
                             (prefixSum[right + k] - prefixSum[right]);
            if (currSum > maxSum)
            {
                maxSum = currSum;
                ans = {left, i, right};
            }
        }

        return ans;
    }
};