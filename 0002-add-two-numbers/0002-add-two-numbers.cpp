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
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = (sum > 9) ? 1 : 0;

            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
        }

        if (carry ==1)
            ptr->next = new ListNode(carry);

        return dummy->next;
        /*
        ALTERNATE SOLN

        ListNode* temp = new ListNode();
        ListNode* curr = temp;
        int carry = 0;

        while (l1 || l2 || carry) {
            int a = (l1 != nullptr) ? l1->val : 0;
            int b = (l2 != nullptr) ? l2->val : 0;

            int sum = a + b + carry;
            carry = (sum > 9) ? 1 : 0;
            int digit = sum % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }

        return temp->next;
        */
    }
};