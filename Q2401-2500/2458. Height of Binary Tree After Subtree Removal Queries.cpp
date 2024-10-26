class Solution
{
public:
    unordered_map<int, int> left, right, ans;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftAns = height(root->left);
        int rightAns = height(root->right);
        left[root->val] = leftAns;
        right[root->val] = rightAns;
        return max(leftAns, rightAns) + 1;
    }
    void solve(TreeNode *root, int maxi, int depth)
    {
        if (root == NULL)
            return;
        ans[root->val] = maxi;
        solve(root->left, max(maxi, depth + right[root->val]), depth + 1);
        solve(root->right, max(maxi, depth + left[root->val]), depth + 1);
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        height(root);
        solve(root->left, right[root->val], 1);
        solve(root->right, left[root->val], 1);
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            res[i] = ans[queries[i]];
        }
        return res;
    }
};