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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2){
        ListNode *h1 = list1;
        for (int i = 0; i < a - 1; i++){
            h1 = h1->next;
        }
        ListNode *h2 = h1->next;
        ListNode *temp2 = list2;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }

        for (int i = 0; i < b - a + 1; i++){
            h2 = h2->next;
        }
        h1->next = list2;
        temp2->next = h2;
        return list1;
    }
};