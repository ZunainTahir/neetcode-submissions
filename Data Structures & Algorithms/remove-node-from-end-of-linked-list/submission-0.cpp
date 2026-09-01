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
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        n = count - n;
        if(n==0) return head->next;
        ListNode* prev=nullptr;
        count = 0;
        temp = head;
        while(count!=n){
            prev = temp;
            temp = temp->next;
            count++;
        }

        ListNode* nxt = temp->next;
        prev->next = nxt;
        temp->next = nullptr;

        return head;
    }
};
