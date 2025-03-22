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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *curr = head;
        ListNode *l = new ListNode(0);
        ListNode *c = l;
        while (curr != NULL)
        {
            if (curr->val < x)
            {
                c->next = new ListNode(curr->val);
                c = c->next;
            }
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL)
        {
            if (curr->val >= x)
            {
                c->next = new ListNode(curr->val);
                c = c->next;
            }
            curr = curr->next;
        }
        return l->next;
    }
};