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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* ptr = temp;
        int carry = 0;

        while (l1 || l2 || carry) {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;

            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            ptr->next = new ListNode(digit);
            ptr = ptr->next;
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }

        return temp->next;
    }
};