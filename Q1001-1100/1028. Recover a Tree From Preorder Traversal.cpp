
class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.size();
        unordered_map<int, stack<TreeNode *>> mp;
        int i = 0;
        string s = "";
        while (i < n && traversal[i] != '-')
        {
            s += traversal[i];
            i++;
        }
        TreeNode *root = new TreeNode(stoi(s));
        mp[0].push(root);
        int count = 0;
        s = "";

        for (int j = i; j < n; j++)
        {
            if (traversal[j] != '-')
            {
                if (j == n - 1 || (j + 1 < n && traversal[j + 1] == '-'))
                {
                    s += traversal[j];
                    TreeNode *top = mp[count - 1].top();
                    TreeNode *newNode = new TreeNode(stoi(s));
                    if (!top->left)
                    {
                        top->left = newNode;
                    }
                    else if (!top->right)
                    {
                        top->right = newNode;
                    }
                    mp[count].push(newNode);
                    count = 0;
                    s = "";
                }
                else
                {
                    s += traversal[j];
                }
            }
            else
            {
                count++;
            }
        }
        return root;
    }
};