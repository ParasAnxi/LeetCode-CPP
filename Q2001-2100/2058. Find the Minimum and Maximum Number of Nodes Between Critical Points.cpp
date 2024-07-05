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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;
        while (curr != nullptr && curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                ans.push_back(pos);
            }
            prev = prev->next;
            curr = curr->next;
            pos++;
        }
        if (ans.size() < 2) {
            return {-1, -1};
        }
        int mini = INT_MAX;
        for (int i = 1; i < ans.size(); i++) {
            mini = min(mini, ans[i] - ans[i - 1]);
        }
        int maxDist = ans.back() - ans.front();

        return {mini, maxDist};
    }
};