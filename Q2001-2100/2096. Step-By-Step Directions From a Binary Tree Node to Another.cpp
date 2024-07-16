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
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *first = NULL;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->val == startValue)
            {
                first = curr;
                break;
            }

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        unordered_map<int, TreeNode *> parents;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                parents[curr->left->val] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parents[curr->right->val] = curr;
                q.push(curr->right);
            }
        }

        unordered_set<TreeNode *> visited;
        q.push(first);
        unordered_map<TreeNode *, pair<TreeNode *, char>> path;

        TreeNode *des = NULL;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            visited.insert(curr);

            if (curr->val == destValue)
            {
                des = curr;
                break;
            }

            if (parents.find(curr->val) != parents.end() && visited.find(parents[curr->val]) == visited.end())
            {
                TreeNode *parent = parents[curr->val];
                q.push(parent);
                path[parent] = make_pair(curr, 'U');
            }

            if (curr->left && visited.find(curr->left) == visited.end())
            {
                q.push(curr->left);
                path[curr->left] = make_pair(curr, 'L');
            }

            if (curr->right && visited.find(curr->right) == visited.end())
            {
                q.push(curr->right);
                path[curr->right] = make_pair(curr, 'R');
            }
        }

        stack<char> res;
        TreeNode *curr = des;

        while (curr != first)
        {
            auto it = path.find(curr);
            if (it != path.end())
            {
                res.push(it->second.second);
                curr = it->second.first;
            }
        }

        string ans;
        while (!res.empty())
        {
            ans += res.top();
            res.pop();
        }

        return ans;
    }
};