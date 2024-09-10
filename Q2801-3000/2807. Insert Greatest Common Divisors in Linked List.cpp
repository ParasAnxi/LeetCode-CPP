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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;
        while (temp->next)
        {
            int val1 = temp->val;
            int val2 = temp->next->val;
            int val3 = __gcd(val1, val2);
            ListNode *mid = new ListNode(val3);
            mid->next = temp->next;
            temp->next = mid;
            temp = temp->next->next;
        }
        return head;
    }
};