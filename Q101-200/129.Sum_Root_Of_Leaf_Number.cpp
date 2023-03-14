 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
  };
 
#define ll long long
class Solution {
public:

    void dfs(TreeNode *root, ll &ans , ll temp){
        if(root->left== nullptr && root->right==nullptr){
            temp = temp*10 + root->val;
            ans+=temp;
            return;
        }
        temp = temp*10 + root->val;
        if(root->left) dfs(root->left,ans,temp);
        if(root->right) dfs(root->right,ans,temp);
    }

    int sumNumbers(TreeNode* root) {
        ll ans =0;
        dfs(root,ans,0);
        return int(ans);
    }
};