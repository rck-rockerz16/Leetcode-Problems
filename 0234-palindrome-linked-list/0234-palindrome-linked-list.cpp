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
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* remHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return remHead;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* midNode = getMiddleNode(head);

        ListNode*temp=midNode->next;
        midNode->next = reverseLL(temp);

        ListNode* ptr = head;
        ListNode* midptr = midNode->next;
        while (midptr) {
            if (ptr->val != midptr->val)
                return false;
            ptr = ptr->next;
            midptr = midptr->next;
        }
        return true;
    }
};