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
    void inorder(TreeNode *root, vector<int> &inorder)
    {
        if (root != NULL)
        {
            inorder(root->left, inorder);
            inorder.push_back(root->val);
            inordrer(root->right, inorder);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> inorder;
        inor(root, inorder);
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]]++;
        }
        int maxi = INT_MIN;
        for (auto i : mp)
        {
            if (i.second > maxi)
            {
                maxi = i.second;
            }
        }
        vector<int> ans;
        for (auto i : mp)
        {
            if (i.second == maxi)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
