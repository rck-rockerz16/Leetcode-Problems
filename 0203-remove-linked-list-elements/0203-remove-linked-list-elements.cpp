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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr && head->val == val)
            return nullptr;

        ListNode newHead(0, head);
        ListNode* ptr = &newHead;

        while (ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            } else
                ptr = ptr->next;
        }

        return newHead.next;
    }
};