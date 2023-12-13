class Solution
{
public:
    int col(vector<vector<int>> &mat, int i, int index)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            if (mat[j][index] == 1 && j != i)
                return 0;
        }
        return 1;
    }

    int row(vector<vector<int>> &mat, int i)
    {
        int index = -1;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                if (index >= 0)
                    return -1;
                else
                    index = j;
            }
        }
        return index;
    }

public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int specials = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            int index = row(mat, i);
            if (index >= 0 && col(mat, i, index))
                specials++;
        }

        return specials;
    }
};