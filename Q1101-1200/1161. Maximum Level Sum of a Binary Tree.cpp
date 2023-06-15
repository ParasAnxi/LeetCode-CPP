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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=0,maxsum=INT_MIN,currSum=0,s,currlevel=1;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            s=q.size();
            currSum=0;
            while(s--){
                temp=q.front();
                q.pop();
                currSum+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(currSum>maxsum){
                maxsum=currSum;
                ans=currlevel;
            }
            currlevel++;
        }
        return ans;
    }
};