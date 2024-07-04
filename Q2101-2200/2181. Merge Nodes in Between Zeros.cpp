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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *prev = head, *next = head->next;
        ListNode *curr(NULL), *ans(NULL);
        int sum;
        while (next != NULL) {
            sum = 0;
            while (next->val != 0) {
                sum += next->val;
                next = next->next;
            }
            ListNode *p = new ListNode(sum);
            if (curr == NULL) {
                curr = p;
                ans = p;
            } else {
                curr->next = p;
                curr = p;
            }
            prev = next;
            next = next->next;
        }

        return ans;
    }
};