
class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        int freq = 0, ans = 0;
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            ans += nums[i];
            if (ans == k)
            {
                freq++;
            }
            if (m.find(ans - k) != m.end())
            {
                freq += m[ans - k];
            }
            m[ans]++;
        }
        return freq;
    }
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int count = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            vector<int> result(matrix[0].size(), 0);
            for (int j = i; j < matrix.size(); ++j){
                for (int k = 0; k < matrix[0].size(); ++k){ 
                    result[k] += matrix[j][k];
                }
                count += solve(result, target);
            }
        }
        return count;
    }
};