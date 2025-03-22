class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<vector<int>> indexes;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            indexes.push_back({nums[i], i});

        sort(indexes.begin(), indexes.end());
        vector<queue<int>> comp;
        vector<int> indComp(n);
        int i = 0, compNo = 0;
        while (i < n)
        {
            queue<int> q;
            q.push(indexes[i][0]);
            indComp[indexes[i][1]] = compNo;
            int j = i + 1;
            while (j < n && abs(indexes[j - 1][0] - indexes[j][0]) <= limit)
            {
                q.push(indexes[j][0]);
                indComp[indexes[j][1]] = compNo;
                j++;
            }
            i = j;
            compNo++;
            comp.push_back(q);
        }
        for (int i = 0; i < n; i++)
        {
            int component = indComp[i];
            nums[i] = comp[component].front();
            comp[component].pop();
        }
        return nums;
    }
};