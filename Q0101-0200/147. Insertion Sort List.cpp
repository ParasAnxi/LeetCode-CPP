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
using vi = vector<int>;
#define pb push_back
#define ln ListNode
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    vi v;
    while (head) {
      v.pb(head->val);
      head = head->next;
    }
    ln *root = NULL, *curr = NULL;
    sort(v.begin(), v.end());
    for (auto u : v) {
      ln *temp = new ln(u);
      if (root == NULL) {
        root = temp;
        curr = temp;
      } else {
        curr->next = temp;
        curr = curr->next;
      }
    }
    return root;
  }
};