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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        map<ListNode*, bool> mp;
        ListNode* curr = headA;
        while (curr) {
            mp[curr]=true;
            curr = curr->next;
        }
        curr = headB;
        while (curr) {
            if (mp[curr]==true)
                return curr;
            curr = curr->next;
        }
        return nullptr;
    }
};