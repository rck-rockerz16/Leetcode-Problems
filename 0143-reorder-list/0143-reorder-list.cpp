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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        stack<ListNode*> st;
        ListNode* curr = head;
        
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        int sizeOfStack = st.size();
        curr = head;

        while (sizeOfStack > 1) {
            ListNode* topNode = st.top();
            st.pop();
            sizeOfStack -= 2;

            topNode->next = curr->next;
            curr->next = topNode;

            curr = curr->next->next;
        }

        curr->next = nullptr;
    }
};