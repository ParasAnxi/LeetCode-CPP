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
    void CheckPalindrome(vector<int> &freq, int &ans)
    {
        int oddfreq = 0;
        for (auto &itr : freq)
        {
            if (itr & 1)
                oddfreq++;
        }
        if (oddfreq <= 1)
            ans++;
    }

    void preOrderTraversal(TreeNode *&root, vector<int> &freq, int &ans)
    {

        if (!root->left && !root->right)
        {
            freq[root->val]++;

            CheckPalindrome(freq, ans);
            freq[root->val]--;
            return;
        }

        freq[root->val]++;

        if (root->left)
        {
            preOrderTraversal(root->left, freq, ans);
        }

        if (root->right)
        {
            preOrderTraversal(root->right, freq, ans);
        }

        freq[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root){
        vector<int> freq(10, 0);
        int path = 0;
        preOrderTraversal(root, freq, path);
        return path;
    }
};