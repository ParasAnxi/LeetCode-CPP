class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;
        vector<int> one(1);
        one[0] = 1;
        ans.push_back(one);
        if (numRows == 1)
            return ans;
        vector<int> two(2);
        two[0] = 1;
        two[1] = 1;
        ans.push_back(two);
        if (numRows == 2)
            return ans;
        for (int i = 2; i < numRows; i++)
        {
            vector<int> temp;
            for (int k = 0; k < i + 1; k++)
            {
                if (k == 0)
                    temp.push_back(1);
                else if (k == i)
                    temp.push_back(1);
                else
                {
                    int first = ans[i - 1][k - 1];
                    int second = ans[i - 1][k];
                    temp.push_back(first + second);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};