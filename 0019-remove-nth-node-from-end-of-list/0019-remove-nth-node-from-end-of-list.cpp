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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode* temp = prev;
        ListNode* t = NULL;

        int i = 0;
        if (n == 1) {
            prev = prev->next;
        } else {
            while (temp != NULL && i != n-1) {
                t = temp;
                i++;
                temp = temp->next;
            }
            if (temp != NULL) {
                t->next = temp->next;
            }
        }

            curr = prev;
            prev = NULL;
            nxt = NULL;

            while (curr != NULL) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
        return prev;
    }
};