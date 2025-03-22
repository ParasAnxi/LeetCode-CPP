class Solution
{
public:
    int find(int a, vector<int> &parent)
    {
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = find(parent[a], parent);
    }
    void unionSets(int a, int b, int &count, vector<int> &parent,
                   vector<int> &rank)
    {
        int parentA = find(a, parent);
        int parentB = find(b, parent);
        if (parentA == parentB)
        {
            count++;
        }
        else
        {
            if (rank[parentA] > rank[parentB])
            {
                parent[parentB] = parentA;
            }
            else if (rank[parentA] < rank[parentB])
            {
                parent[parentA] = parentB;
            }
            else
            {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int dots = n + 1;
        int count = 0;
        vector<int> parent;
        vector<int> rank;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;

        for (int i = 0; i < parent.size(); ++i)
        {
            parent[i] = i;
        }

        for (int i = 0; i < dots; ++i)
        {
            for (int j = 0; j < dots; ++j)
            {
                if (i == 0 || j == 0 || i == n || j == n)
                {
                    int cell = i * dots + j;
                    unionSets(0, cell, count, parent, rank);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '\\')
                {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2, count, parent, rank);
                }
                else if (grid[i][j] == '/')
                {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2, count, parent, rank);
                }
            }
        }
        return count;
    }
};