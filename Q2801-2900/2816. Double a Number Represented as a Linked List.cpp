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
    ListNode *doubleIt(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        stack<int> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        ListNode *ans = NULL;
        int c = 0;
        while (!st.empty() || c != 0)
        {
            int x = 0;
            if (!st.empty())
            {
                x = st.top();
                st.pop();
            }
            x *= 2;
            int y = x % 10 + c;
            c = x / 10;
            ListNode *newn = new ListNode(y);
            newn->next = ans;
            ans = newn;
        }
        return ans;
    }
};