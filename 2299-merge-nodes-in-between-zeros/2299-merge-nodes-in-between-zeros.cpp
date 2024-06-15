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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        int sum = 0;

        for (ListNode* ptr = head->next; ptr != nullptr; ptr = ptr->next) {
            sum += ptr->val;
            if (ptr->val == 0) {
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum = 0;
            }
        }


        return dummy.next;
    }
};