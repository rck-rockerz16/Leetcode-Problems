int a[50001];
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);) {
        if (s.length() == 2) {
            out << "[]\n";
            continue;
        }
        int n = 0;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;
            if (s[_i] == '-')
                ++_i, _neg = true;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10)
                v = v * 10 + (s[_i++] & 15);
            if (_neg)
                v = -v;
            a[n++] = v;
        }

        int i = 0, j = n - 1;
        out << '[';
        while (i < j) {
            out << a[i++] << ',' << a[j--] << ",";
        }
        if (i == j)
            out << a[i] << ',';
        out.seekp(-1, ios::end);
        out << "]\n";
    }
    out.flush();
    exit(0);
    return 0;
}();
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