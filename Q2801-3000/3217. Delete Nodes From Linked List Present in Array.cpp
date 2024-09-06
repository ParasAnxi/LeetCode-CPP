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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        set<int> s;
        for (auto i : nums)
            s.insert(i);
        while (head != NULL)
        {
            if (s.find(head->val) == s.end())
            {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;
        return ans->next;
    }
};