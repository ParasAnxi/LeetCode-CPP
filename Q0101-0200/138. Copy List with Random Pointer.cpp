/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        unordered_map<Node *, Node *> oldToNewNode;
        Node *originalNode = head;
        Node *cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};