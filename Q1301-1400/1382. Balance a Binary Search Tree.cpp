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
class Solution
{
public:
    void inO(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;
        inO(root->left, nodes);
        nodes.push_back(root->val);
        inO(root->right, nodes);
    }

    TreeNode *update(vector<int> &nodes, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (right - left) / 2 + left;
        TreeNode *node = new TreeNode(nodes[mid]);
        node->left = update(nodes, left, mid - 1);
        node->right = update(nodes, mid + 1, right);
        return node;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nodes;
        inO(root, nodes);
        return update(nodes, 0, nodes.size() - 1);
    }
};