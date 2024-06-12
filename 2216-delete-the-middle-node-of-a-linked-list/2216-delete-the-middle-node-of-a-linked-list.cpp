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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            head = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        ListNode* temp;
        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};