/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *ans = node->next;
        while (ans)
        {
            if (ans)
                node->val = ans->val;
            if (!ans->next)
                node->next = NULL;
            node = ans;
            ans = ans->next;
        }
    }
};