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
    bool hasCycle(ListNode* head) {
        ListNode* onestep = head,* twostep = head;
        if (!head || !head->next)
            return NULL;

        while (twostep && twostep->next) {
            twostep = twostep->next->next;
            onestep = onestep->next;

            if (onestep == twostep)
                return true; 
        }
        return false;
        // Hashmap Technique

        // ListNode *ptr=head;
        // map<ListNode *,int>mp;
        // while(ptr!=NULL)
        // {
        //     mp[ptr->next]++;
        //     if(mp[ptr->next]>1)
        //         return true;
        //     ptr=ptr->next;
        // }
        // return false;
    }
};