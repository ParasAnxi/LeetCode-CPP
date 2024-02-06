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
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *tail = head;
        int size = 1;
        while (tail->next != NULL)
        {
            size++;
            tail = tail->next;
        }
        tail->next = head;
        k = k % size;
        int last = size - k;
        ListNode *temp = head;
        while (last != 1)
        {
            temp = temp->next;
            last--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};