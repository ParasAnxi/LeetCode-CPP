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
    ListNode *removeNodes(ListNode *head)
    {
        stack<ListNode *> s;
        while (head != NULL)
        {
            s.push(head);
            head = head->next;
        }
        ListNode *ans = s.top();
        s.pop();
        while (!s.empty())
        {
            while (!s.empty() and s.top()->val < ans->val)
            {
                s.top()->next = NULL;
                delete s.top();
                s.pop();
            }
            if (!s.empty())
            {
                s.top()->next = ans;
                ans = s.top();
                s.pop();
            }
        }
        return ans;
    }
};