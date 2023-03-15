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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool isNull=false;

        while(!q.empty()){ 
            int levelSize=q.size();
            while(levelSize--){    
                TreeNode* tp=q.front();
                q.pop();
                if(!tp) isNull=true;
                else{
                    if(isNull) return false;
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        return true;
    }
};