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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        /* head = temp; 
        We can also point the existing head to the actual head
        of the list or just return the temp which is the head */
        return temp;
    }
};