/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return NULL;

    ListNode *first = headA;
    ListNode *second = headB;
    while (first != second) {
      if (!first) {
        first = headB;
      } else {
        first = first->next;
      }

      if (!second) {
        second = headA;
      } else {
        second = second->next;
      }
    }
    return first;
  }
};