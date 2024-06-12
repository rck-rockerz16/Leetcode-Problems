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
    }
};