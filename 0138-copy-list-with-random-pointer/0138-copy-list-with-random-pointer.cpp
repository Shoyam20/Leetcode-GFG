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
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;

        while(temp!=NULL)
        {
            Node *newNode= new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }


        temp=head;
        
        while(temp!=NULL)
        {
            Node *t=temp->next;
            if(temp->random==NULL)
                t->random=NULL;
            else
                t->random=temp->random->next;
            temp=temp->next->next;
        }

        // Node *newhead=head->next;
        Node *clone=new Node(-1);
        temp=head;
        Node *temp2=clone;

        while(temp!=NULL)
        {
            temp2->next=temp->next;
            temp->next=temp->next->next;

            temp2=temp2->next;
            temp=temp->next;
        }
        return clone->next;

    }
};