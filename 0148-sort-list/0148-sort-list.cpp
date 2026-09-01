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
    ListNode* findmid(ListNode *start )
    {
        ListNode *slow=start;
        ListNode *fast=start->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    ListNode * merge(ListNode *lefthead,ListNode*righthead)
    {
        // ListNode *dummy = new ListNode(-1);
        // ListNode *temp = dummy; 
        ListNode dummy(-1);
ListNode *temp = &dummy;

        while(lefthead!=NULL && righthead!=NULL)
        {
            if(lefthead->val < righthead->val)
            {
                temp->next=lefthead;
                temp=temp->next;
                lefthead=lefthead->next;
            }
            else{
                temp->next=righthead;
                temp=temp->next;
                righthead=righthead->next;
            }
        }
        while(lefthead!=NULL)
        {
            temp->next=lefthead;
            temp=temp->next;
            lefthead=lefthead->next;
        }
        while(righthead!=NULL)
        {
            temp->next=righthead;
            temp=temp->next;
            righthead=righthead->next;
        }

        return dummy.next;
    }
    ListNode *ms(ListNode *head)
    {
        if(head==NULL || head->next==NULL) return head;

        ListNode * middle=findmid(head);

        ListNode *lefthead=head;
        ListNode *righthead=middle->next;
        middle->next=NULL;

        lefthead=ms(lefthead);
        righthead=ms(righthead);

        return merge(lefthead,righthead);
    }
    ListNode* sortList(ListNode* head) {
        

        if(head==NULL || head->next==NULL) return head;
        return ms(head);



        
    }
};