/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(TreeNode *treeNode, ListNode *node)
    {
        if (node == NULL)
        {
            return true;
        }
        if (treeNode == NULL)
        {
            return false;
        }

        if (treeNode->val == node->val)
        {
            return solve(treeNode->left, node->next) || solve(treeNode->right, node->next);
        }

        return false;
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == NULL)
        {
            return false;
        }

        return solve(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};