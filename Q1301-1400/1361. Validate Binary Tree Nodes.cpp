class Solution
{
public:
    bool solve(vector<int> &left, vector<int> &right, int src, int n, vector<bool> &visit)
    {
        if (visit[src])
            return false;
        bool ans = 1;
        visit[src] = 1;

        if (left[src] != -1)
            ans = ans && solve(left, right, left[src], n, visit);

        if (right[src] != -1)
            ans = ans && solve(left, right, right[src], n, visit);
        return ans;
    }
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                ind[leftChild[i]]++;
            if (rightChild[i] != -1)
                ind[rightChild[i]]++;
        }
        bool cond1 = 0;
        int src = 0;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
            {
                if (!cond1)
                {
                    src = i;
                    cond1 = 1;
                }
                else
                    return false;
            }
        }
        if (!cond1)
            return false;
        vector<bool> visit(n, 0);
        int ans = solve(leftChild, rightChild, src, n, visit);
        if (!ans)
            return false;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
                return false;
        }
        return true;
    }
};