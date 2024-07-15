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
    TreeNode *create_tree(TreeNode *&root, int val, unordered_map<int, vector<int>> &nodes){
        if (root == NULL){
            if (val != 0)
                root = new TreeNode(val);
            else{
                return root;
            }
        }
        if (nodes.find(root->val) != nodes.end()){
            int left_val = nodes[root->val][0];
            int right_val = nodes[root->val][1];
            root->left = create_tree(root->left, left_val, nodes);
            root->right = create_tree(root->right, right_val, nodes);
        }
        return root;
    }
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions){
        unordered_map<int, vector<int>> nodes;
        unordered_set<int> child;
        int root_val;

        for (vector<int> &v : descriptions){
            if (nodes.find(v[0]) != nodes.end()){
                if (v[2]){
                    nodes[v[0]][0] = v[1];
                }
                else{
                    nodes[v[0]][1] = v[1];
                }
            }
            else{
                if (v[2]){
                    nodes[v[0]] = {v[1], 0};
                }
                else{
                    nodes[v[0]] = {0, v[1]};
                }
            }
            child.insert(v[1]);
        }

        for (vector<int> &v : descriptions)
        {
            if (child.find(v[0]) == child.end())
            {
                root_val = v[0];
                break;
            }
        }
        TreeNode *root = NULL;
        create_tree(root, root_val, nodes);
        return root;
    }
};