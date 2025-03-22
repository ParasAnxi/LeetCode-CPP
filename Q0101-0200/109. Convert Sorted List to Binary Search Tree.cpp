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
class Solution {
public:
    TreeNode* constructBST(ListNode *leftHead, ListNode *rightHead) {
        if (leftHead == rightHead)
            return NULL;
        ListNode *slow = leftHead, *fast = leftHead;
        while (fast != rightHead && fast -> next != rightHead) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        TreeNode *root = new TreeNode(slow -> val);
        root -> left = constructBST(leftHead, slow);
        root -> right = constructBST(slow -> next, rightHead);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head -> next == NULL) {
            TreeNode *root = new TreeNode(head -> val);
            return root;
        }
        return constructBST(head, NULL);
    }
};