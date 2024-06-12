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
    ListNode* middleNode(ListNode* head) {
        ListNode* onestep = head;
        ListNode* twostep = head;

        while (twostep != nullptr && twostep->next != nullptr) {
            onestep = onestep->next;
            twostep = twostep->next->next;
        }

        return onestep;

        /*
        2nd Approach

        ListNode* ptr = head;
        int size = 0;
        while(ptr!=nullptr)
        {
            ++size;
            ptr=ptr->next;
        }

        ptr=head;
        for(int i=0;i<size/2;i++)
            ptr=ptr->next;

        return ptr;
        */
    }
};