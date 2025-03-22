/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> solution;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> PathToTarget = findPath(root, target);
        while(PathToTarget.size() > k + 1) {
            PathToTarget.pop_back();
        }
        vector<int> solution;
        if(PathToTarget.size() == k + 1){
            solution.push_back(PathToTarget.back()->val);
            PathToTarget.pop_back();
        }
        TreeNode *temp;
        int dist = PathToTarget.size()+1;
        while(!PathToTarget.empty()) {
            temp = PathToTarget.back();
            if(temp == target){
                addChildren(target,k,solution);
                PathToTarget.pop_back();
            } else {
                dist-= 2;
                PathToTarget.pop_back();
                temp = (temp->right == PathToTarget.back()) ? temp->left : temp->right;
                dist++;
                if(temp) addChildren(temp,k - dist,solution);
            }
        }
        return solution;
    }

    vector<TreeNode*> findPath(TreeNode* root, TreeNode* target) {
        unordered_map<TreeNode*,TreeNode*> parentOf;
        queue<TreeNode*> level;
        level.push(root);
        TreeNode *temp = root;
        while(temp->val != target->val){
            if(temp->left){
                level.push(temp->left);
                parentOf[temp->left] = temp;
            }
            if(temp->right){
                level.push(temp->right);
                parentOf[temp->right] = temp;
            }
            level.pop();
            temp = level.front();
        }
        vector<TreeNode*> solution;
        while(temp->val!=root->val) {
            solution.push_back(temp);
            temp = parentOf[temp];
        }
        solution.push_back(root);
        return solution;
    }

    void addChildren(TreeNode* root, int distance, vector<int> &solution){
        if(distance == 0) {
            solution.push_back(root->val);
            return;
        }
        if(root->left) {
            addChildren(root->left,distance-1,solution);
        }
        if(root->right) {
            addChildren(root->right,distance-1,solution);
        }
    } 
};