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
public
    ListNode partition(ListNode head, int x)
    {
        ListNode ans = new ListNode(0);
        ListNode smaller = ans;
        ListNode greater = new ListNode(0);
        ListNode great = greater;
        while (head != null)
        {
            int val = head.val;
            ListNode temp = new ListNode(val);
            if (val >= x)
            {
                greater.next = temp;
                greater = temp;
            }
            else
            {
                smaller.next = temp;
                smaller = temp;
            }
            head = head.next;
        }
        smaller.next = great.next;
        greater.next = null;
        return ans.next;
    }
};