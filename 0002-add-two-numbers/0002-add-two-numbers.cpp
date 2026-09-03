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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int c=0;
        int x;
        if(l1==NULL) return NULL;
        ListNode*temp1=l1;
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        ListNode*temp2=l2;

        while(temp1!=NULL && temp2!=NULL)
        {
            sum=(temp1->val)+(temp2->val)+c;
            ListNode*newNode=new ListNode(sum%10);
            temp->next=newNode;
            c=sum/10;
            temp=temp->next;

            temp1=temp1->next;
            temp2=temp2->next;
        }

        while(temp1!=NULL)
        {
            sum=(temp1->val)+c;
           ListNode*newNode=new ListNode(sum%10);
            temp->next=newNode;
            c=sum/10;
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            sum=(temp2->val)+c;
            ListNode*newNode=new ListNode(sum%10);
            temp->next=newNode;
            c=sum/10;
            temp=temp->next;
            temp->val=x;
            temp2=temp2->next;
        }
        if(c==1)
        {
            ListNode*newNode=new ListNode(c);
            temp->next=newNode;
        }
        return dummy->next;
    }
};