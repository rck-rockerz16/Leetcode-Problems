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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int cnt = 0;
        bool inComponent = false;

        while (head != nullptr) {
            if (numSet.find(head->val) != numSet.end()) {
                if (inComponent == false) {
                    cnt++;
                    inComponent = true;
                }
            } else {
                inComponent = false;
            }
            head = head->next;
        }

        return cnt;
    }
};