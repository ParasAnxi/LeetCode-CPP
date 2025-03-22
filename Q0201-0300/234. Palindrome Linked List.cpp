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
    bool isPalindrome(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *current = head;
        vector<int> ans;
        ListNode *temp = NULL;
        int length = 0;
        bool result = 1;

        while (current != NULL)
        {
            ans.push_back(current->val);
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            length++;
        }

        for (int i = 0; i <= length / 2; i++)
        {
            if (ans[i] != prev->val)
            {
                return 0;
            }
            else
            {
                prev = prev->next;
            }
        }
        return result;
    }
};