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

class Solution {
private:
    void insert(Node* &head, Node* &tail, int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

    }

public:
    Node* copyRandomList(Node* head) {
        //step 1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while(temp)
        {
            insert(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        //step 2 - Add cloneNode in between originalNode

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode!= NULL)
        {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        //step 3 - Random pointer copy
        temp = head;
        while(temp)
        {
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random = temp->random->next;
                }
                // else{
                //     temp->next = temp->random;
                // }
            }
            temp = temp->next->next;
        }

        //step 4 - Revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode!= NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL){
            cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
            }
        }

        //step 5 - return 
        return cloneHead;

    }
};