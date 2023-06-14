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
        vector<int> v;
        void findvector(TreeNode* root){
        if(root==NULL)
        return ;
        findvector(root->left);
        v.push_back(root->val);
        findvector(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        findvector(root);
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){

        mini=min(mini,abs(v[i]-v[j]));    

        }
    }
     return mini;   

    }
};