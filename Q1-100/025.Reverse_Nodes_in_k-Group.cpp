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
    ListNode* F(ListNode *cur) {
        ListNode *next = cur, *pre = nullptr;
        while(cur) {
            next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head-> next || k == 1) return head;

        ListNode *cur = head;
        ListNode *ans = nullptr, *temp = nullptr;

        while(cur) {
            ListNode *left = cur, *right = nullptr;
            int cnt = 0;
            while(cur && cnt != k) {
                right = cur;
                cur = cur -> next;
                cnt++;
            }

            if(cnt != k) {
                if(!ans) return head;
                temp -> next = left;
                return ans;
            }

            right -> next = nullptr;
            ListNode *r = F(left);

            if(!ans) ans = r;
            else temp -> next = r;
            temp = left;
        }
        return ans;
    }
};