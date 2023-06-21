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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        if(head->next==NULL)
            return NULL;
        ListNode* fast = head->next;
        if(fast->next == NULL)
        {
            slow->next = NULL;
            return head;
        }
        ListNode* temp = NULL;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            temp = slow;
            slow = slow->next;   
        }
        if(fast==NULL)
        {
            temp->next = slow->next;
            return head;
        }
        else if(fast->next == NULL)
        {
            temp->next->next = slow->next->next;
            return head;
        }
        return NULL;
    }
};