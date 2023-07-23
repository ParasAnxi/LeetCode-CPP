class Solution
{
public:
    vector<TreeNode *> get_trees(int n, vector<vector<TreeNode *>> &dp)
    {
        if (n % 2 == 0)
        {
            return {};
        }
        if (n == 1)
        {
            TreeNode *root = new TreeNode(0);
            return {root};
        }
        if (dp[n].size() > 0)
        {
            return dp[n];
        }
        vector<TreeNode *> ans;
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> left_tree = get_trees(i, dp);
            vector<TreeNode *> right_tree = get_trees(n - 1 - i, dp);
            for (auto sub_left : left_tree)
            {
                for (auto sub_right : right_tree)
                {
                    TreeNode *node = new TreeNode(0);
                    node->left = sub_left;
                    node->right = sub_right;
                    ans.push_back(node);
                }
            }
        }
        return dp[n] = ans;
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<vector<TreeNode *>> dp(n + 1);
        return get_trees(n, dp);
    }
};