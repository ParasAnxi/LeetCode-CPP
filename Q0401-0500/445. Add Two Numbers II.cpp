class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *nex;
        while (head)
        {
            nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }

    ListNode *addList(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while (head1 || head2 || carry)
        {
            int sum = 0;
            if (head1)
            {
                sum += head1->val;
                head1 = head1->next;
            }
            if (head2)
            {
                sum += head2->val;
                head2 = head2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head1 = reverseList(l1);
        ListNode *head2 = reverseList(l2);
        return reverseList(addList(head1, head2));
    }
};