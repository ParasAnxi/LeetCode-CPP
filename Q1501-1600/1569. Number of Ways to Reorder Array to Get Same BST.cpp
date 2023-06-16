class Solution {
public:

    int mod = 1e9+7;
    vector<vector<long long>> v;
    void insert(TreeNode *root, int num){
    
        if(root->val == -1){
            root->val = num;
        }
        else{
            if(root->val < num){
                if(!root->right)root->right = new TreeNode(-1);
                insert(root->right, num);
            }
            else{
                if(!root->left)root->left = new TreeNode(-1);
                insert(root->left, num);
            }
        }
    }
    pair<int, int> dp(TreeNode *root){
        if(!root)return {0, 1};
        else{

            auto l = dp(root->left);
            auto r = dp(root->right);

            pair<int, int> p;
            p.first = l.first + r.first + 1;
            p.second = ((( v[p.first - 1][l.first] * l.second) % mod) * r.second) % mod;
            
            return p;
        }
    }

    int numOfWays(vector<int>& nums) {
        
        int n = nums.size();
        if(n>2){
            TreeNode *root = new TreeNode(-1);
            for(int x: nums){
                insert(root, x);
            }

            v.resize(n + 1);
            for(int i = 0; i < n + 1; ++i){
                v[i] = vector<long long>(i + 1, 1);
                for(int j = 1; j < i; ++j){
                    v[i][j] = (v[i-1][j-1] + v[i-1][j]) % mod;
                }
            }

            return dp(root).second - 1;
        }
        else return 0;
    }
};