/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements
{
public:
    TreeNode *root;
    void solve(TreeNode *root)
    {
        if (root == nullptr) return;
        if (root->left) root->left->val = 2 * root->val + 1;
        if (root->right) root->right->val = 2 * root->val + 2;
        solve(root->left);
        solve(root->right);
    }
    FindElements(TreeNode *r)
    {
        root = r;
        root->val = 0;
        solve(root);
    }
    void dfs(TreeNode *root, int x, bool &ans)
    {
        if (root == NULL) return;
        if (root->val == x) ans = true;
        dfs(root->left, x, ans);
        dfs(root->right, x, ans);
    }
    bool find(int target)
    {
        bool ans = false;
        dfs(root, target, ans);
        return ans;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */