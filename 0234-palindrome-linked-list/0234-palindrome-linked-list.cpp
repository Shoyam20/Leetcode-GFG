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
        int sum=0;
        if(head==NULL || head->next==NULL) return true;
        ListNode*temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }

        int i =0 ; 
        int j=v.size()-1;

        while(i<j)
        {
            if(v[i]!=v[j]) return false;
            i++;
            j--;

        }
        return true;
    }
};