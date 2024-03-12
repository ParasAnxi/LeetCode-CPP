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
class Solution{
public:
    ListNode *solve(ListNode *head){
        int sum = 0;
        ListNode *temp = head, *ans = head;
        while(temp){
            sum += temp->val;
            temp = temp->next;
            if (sum == 0){
                ans = temp;
            }
        }
        return ans;
    }
    ListNode *removeZeroSumSublists(ListNode *head){
        head = solve(head);
        ListNode *i = head;
        while (i && i->next){
            i->next = solve(i->next);
            i = i->next;
        }
        return head;
    }
};