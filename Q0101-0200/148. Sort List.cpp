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
#define ln ListNode
class Solution {
public:
  ln *findMid(ln *head) {
    if (!head || !head->next) {
      return head;
    }
    ln *slow = head;
    ln *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  ln *mergeLL(ln *list1, ln *list2) {
    ln *ans = new ln(-1);
    ln *temp = ans;
    while (list1 != NULL && list2 != NULL) {
      if (list1->val < list2->val) {
        temp->next = list1;
        temp = list1;
        list1 = list1->next;
      } else {
        temp->next = list2;
        temp = list2;
        list2 = list2->next;
      }
    }
    if (list1 != NULL) {
      temp->next = list1;
    } else {
      temp->next = list2;
    }
    return ans->next;
  }
  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ln *mid = findMid(head);
    ln *left = head;
    ln *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return mergeLL(left, right);
  }
};