/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* ptr = head;
                while (ptr != fast) {
                    ptr = ptr->next;
                    fast = fast->next;
                }
                return ptr;
            }
        }
        return nullptr;
        /*
        HASHMAP METHOD

        if(!head || !head->next)
            return nullptr;

        unordered_map<ListNode*, bool> mp;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            if (mp[ptr] == true)
                return ptr;
            mp[ptr] = true;
            ptr = ptr->next;
        }
        return nullptr;
        */
    }
};