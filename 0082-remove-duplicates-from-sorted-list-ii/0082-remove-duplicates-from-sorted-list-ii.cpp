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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = new ListNode(0, head);
        ListNode *curr = newHead, *ptr = head;

        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->val == ptr->next->val) {
                while (ptr->next != nullptr && ptr->val == ptr->next->val)
                    ptr = ptr->next;
                curr->next = ptr->next;
            } else
                curr = curr->next;

            ptr = ptr->next;
        }

        return newHead->next;

        /*
        ALTERNATE SOLN
        
        if(head -> val == head -> next -> val){

            while(head && head -> next && head -> val == head -> next -> val){
                while(head -> next && head -> val == head -> next -> val){
                    head = head -> next ; 
                }
                head = head -> next ;
            } 
        }

        ListNode* curr = head ;
        while(curr){

            if(curr -> next && curr -> next -> next && curr -> next -> val == curr -> next -> next -> val){
                
                ListNode* nextNode = curr -> next ;
                int data = nextNode -> val ;  
                while(nextNode && nextNode -> val == data){
                    nextNode = nextNode -> next ; 
                }
                curr -> next = nextNode ; 
            }
            else
                curr = curr -> next ; 
        }

        return head ;
        */
    }
};