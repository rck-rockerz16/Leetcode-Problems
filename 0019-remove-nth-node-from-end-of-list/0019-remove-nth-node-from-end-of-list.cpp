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
        ListNode ptr(0);
        ptr.next = head;
        ListNode* ptr1 = &ptr;
        ListNode* ptr2 = &ptr;

        for (int i = 0; i < n + 1; i++) 
            ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        ListNode* temp = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete temp;

        return ptr.next;
    }
};