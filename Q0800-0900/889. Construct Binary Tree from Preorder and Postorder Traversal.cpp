class Solution
{
public:
    TreeNode *solve(int prestart, int postStart, int preEnd, vector<int> preorder, vector<int> postorder)
    {
        if (prestart > preEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[prestart]);
        if (prestart == preEnd)
        {
            return root;
        }
        int nextNode = preorder[prestart + 1];
        int j = postStart;
        while (postorder[j] != nextNode)
        {
            j++;
        }
        int nums = j - postStart + 1;
        root->left = solve(prestart + 1, postStart, prestart + nums, preorder, postorder);
        root->right = solve(prestart + nums + 1, j + 1, preEnd, preorder, postorder);
        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        return solve(0, 0, n - 1, preorder, postorder);
    }
};