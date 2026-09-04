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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    ListNode* findkth(ListNode* temp, int t) {
        int c = 1;
        while (temp != NULL) {
            if (c == t)
                return temp;
            temp = temp->next;
            c++;
        }

        return NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;

        ListNode* temp = head;
        ListNode *prevNode, *nextNode, *kthNode, *newHead = NULL;
        while (temp != NULL) {
            kthNode = findkth(temp, k);
            if (kthNode == NULL) {
                prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            kthNode = reverse(temp);

            if (newHead == NULL) {
                newHead = kthNode;
            } else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return newHead;
    }
};