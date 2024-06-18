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
private:
    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;

        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while (left && right) {
            if (left->val < right->val) {
                ptr->next = left;
                ptr = left;
                left = left->next;
            } else {
                ptr->next = right;
                ptr = right;
                right = right->next;
            }
        }
        ptr->next = left ? left : right;
        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* midNode = getMidNode(head);

        ListNode* left = head;
        ListNode* right = midNode->next;
        midNode->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        ListNode* sortedList = merge(left, right);
        return sortedList;
    }
};