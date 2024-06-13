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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* newHead = new ListNode(0, head);
        ListNode *curr = newHead, *ptr = head;

        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->val == ptr->next->val) {
                while (ptr->next != nullptr && ptr->val == ptr->next->val)
                    ptr = ptr->next;
                curr->next = ptr->next;
            } else 
                curr = curr->next;
                
            ptr = ptr->next;
        }

        return newHead->next;
    }
};