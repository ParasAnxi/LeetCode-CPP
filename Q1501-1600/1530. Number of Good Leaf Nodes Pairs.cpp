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
class Solution {
public:
    vector<int> dfs(TreeNode* root, int distance, int &count){
        if(!root)
         return {}; 
        if(!root->left && !root->right)
         return {1};

        auto leftAns = dfs(root->left, distance,count);
        auto rightAns = dfs(root->right,distance,count);

        for(auto i:leftAns){ 
            for(auto j:rightAns){
                if(i+j<=distance)
                count++;
            }
        }
        vector<int> ans; 
        for(auto it:leftAns){
            if(it+1<=distance) ans.push_back(it+1);
        }
        for(auto it:rightAns){
            if(it+1<=distance) ans.push_back(it+1);
        }
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
};