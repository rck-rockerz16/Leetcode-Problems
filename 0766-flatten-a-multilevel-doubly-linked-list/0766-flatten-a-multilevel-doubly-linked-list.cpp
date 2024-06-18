/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                // Find the tail of the child list
                Node* childTail = curr->child;
                while (childTail->next) {
                    childTail = childTail->next;
                }

                // Connect the tail of the child list to the next node
                if (curr->next) {
                    curr->next->prev = childTail;
                }
                childTail->next = curr->next;

                // Connect the current node to the child list
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
            }

            // Move to the next node
            curr = curr->next;
        }

        return head;
    }
};