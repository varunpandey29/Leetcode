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
private:
    ListNode* rev(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true; 
        ListNode* slow = head;
        ListNode* fast = head;

        //Find middle of LL
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse a LL
        ListNode* temp = slow->next;
        slow->next = rev(temp);

        //Check for the palindrome
        ListNode* c1 = head;
        ListNode* c2 = slow->next;

        while(c2!=NULL)
        {
            if(c1->val == c2->val)
            {
                c1 = c1->next;
                c2 = c2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

};