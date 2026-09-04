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

        Node *clone=new Node(-1);
        Node *t=clone;
        unordered_map<Node* ,Node *> m;
        while(temp!=NULL)
        {
            Node *newNode= new Node(temp->val);
            t->next=newNode;

            m[temp]=newNode;
            t=t->next;
            temp=temp->next;
        }


        temp=head;
        while(temp!=NULL)
        {
            m[temp]->random=m[temp->random];
            temp=temp->next;
        }
        return clone->next;
    }
};