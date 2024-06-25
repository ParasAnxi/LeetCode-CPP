void dfs(TreeNode *root, int &sum)
{
    if (root == nullptr)
    {
        return;
    }
    dfs(root->right, sum);
    sum = sum + root->val;
    root->val = sum;
    dfs(root->left, sum);
}
TreeNode *bstToGst(TreeNode *root)
{
    int sum = 0;
    dfs(root, sum);
    return root;
}