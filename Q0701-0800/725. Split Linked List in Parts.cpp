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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int size = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            size++;
            curr = curr->next;
        }
        vector<ListNode *> ans(k);
        if (size <= k)
        {
            ListNode *curr = head;
            int i = 0;
            while (curr != NULL)
            {
                ListNode *temp = curr->next;
                curr->next = NULL;
                ans[i] = curr;
                curr = temp;
                i++;
            }
        }
        else
        {
            int extra = size % k;
            int part = size / k;
            int i = 0;
            curr = head;
            while (curr != NULL)
            {
                int p = 0;
                ListNode *res = curr;
                while (curr != NULL && p < part - 1)
                {
                    curr = curr->next;
                    p++;
                }
                if (extra > 0)
                {
                    curr = curr->next;
                    extra--;
                }
                ListNode *temp = curr->next;
                curr->next = NULL;
                ans[i] = res;
                curr = temp;
                i++;
            }
        }
        return ans;
    }
};