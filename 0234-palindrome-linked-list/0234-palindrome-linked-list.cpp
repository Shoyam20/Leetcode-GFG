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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (head == NULL || head->next == NULL)
            return true;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = head;
        ListNode* prev=NULL ;
        ListNode* nxt=NULL ;

        while(curr!=slow){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

    if(fast!=NULL)  
    {
        slow=slow->next;
    }

    while(slow!=NULL)
    {
        if(slow->val!=prev->val)
        {
            return false;
        }
        slow=slow->next;
        prev=prev->next;
    }
    return true;
    }
};