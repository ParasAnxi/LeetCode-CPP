class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> freq(n, 0);
        int c = 0;            
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            freq[A[i] - 1] += 1;
            if (freq[A[i] - 1] == 2)
                c++;

            freq[B[i] - 1] += 1;
            if (freq[B[i] - 1] == 2)
                c++;

            ans[i] = c;
        }
        return ans;
    }
};