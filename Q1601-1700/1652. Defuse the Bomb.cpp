class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {

        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
        {
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (k > 0)
            {

                for (int j = 1; j <= k; j++)
                {
                    int index = (i + j) % n;
                    sum += code[index];
                }
            }
            else
            {

                for (int j = 1; j <= -k; j++)
                {
                    int index = (i - j + n) % n;
                    sum += code[index];
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};