/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *nextNode;
 *     ListNode() : val(0), nextNode(nullptr) {}
 *     ListNode(int x) : val(x), nextNode(nullptr) {}
 *     ListNode(int x, ListNode *nextNode) : val(x), nextNode(nextNode) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;

        ListNode* ptr = head;
        for (int i = 1; i <= k; i++) {
            if (ptr == nullptr)
                return head;
            ptr = ptr->next;
        }

        ListNode *prevNode = nullptr, *currNode = head, *nextNode;
        int cnt = 1;
        while (currNode != nullptr && cnt++ <= k) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        if (nextNode != nullptr)
            head->next = reverseKGroup(nextNode, k);

        return prevNode;
    }
};
