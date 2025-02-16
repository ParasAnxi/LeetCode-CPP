class Solution
{
public:
    bool solve(int i, int n, vector<int> &ans, vector<bool> &check)
    {
        if (i >= ans.size())
        {
            return true;
        }
        if (ans[i] != -1)
        {
            return solve(i + 1, n, ans, check);
        }
        for (int num = n; num > 0; num--)
        {
            if (check[num])
                continue;
            ans[i] = num;
            check[num] = true;
            if (num == 1)
            {
                if (solve(i + 1, n, ans, check) == true)
                    return true;
            }
            else
            {
                int j = i + num;
                if (j < ans.size() && ans[j] == -1)
                {
                    ans[j] = num;
                    if (solve(i + 1, n, ans, check) == true)
                        return true;
                    ans[j] = -1;
                }
            }
            ans[i] = -1;
            check[num] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> check(n + 1, false);
        solve(0, n, ans, check);
        return ans;
    }
};