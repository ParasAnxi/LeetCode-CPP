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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int length=right-left+1;
        if(!head || head->next==NULL || length==1)return head;

        ListNode* curr=head;
        for(int i=1;i<left-1;i++){
            if(curr)curr=curr->next;
            else break;
        }
        ListNode* left_half=(left==1)?NULL:curr;
        curr=(left==1)?curr:curr->next;

        ListNode* right_half=head;
        for(int i=1;i<=right;i++){
            if(right_half)right_half=right_half->next;
            else break;
        }
        ListNode *prev=right_half;

        while(curr && length){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            length--;
        }
        if(left_half==NULL)return prev;
        left_half->next=prev;
        return head;
    }
};