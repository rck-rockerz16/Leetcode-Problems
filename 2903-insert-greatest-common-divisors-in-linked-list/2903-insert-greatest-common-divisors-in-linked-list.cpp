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
static const int __ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        if (str.find(',') == string::npos) {
            cout << str;
            continue;
        }
        stringstream ss(str);
        ss.ignore();
        int prev;
        ss >> prev;
        ss.ignore();
        cout << '[' << prev;
        for (int curr; ss >> curr; ss.ignore()) {
            cout << ',' << gcd(prev, curr) << ',' << curr;
            prev = curr;
        }
        cout << ']';
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    int GreatestCommonDivisors(int num1, int num2) {
        while (num2 != 0) {
            int rem = num1 % num2;
            num1 = num2;
            num2 = rem;
        }
        return num1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head, *nextNode = head->next;
        if (!nextNode)
            return head;

        if (!nextNode->next) {
            ListNode* newNode =
                new ListNode(GreatestCommonDivisors(curr->val, nextNode->val));
            newNode->next = nextNode;
            curr->next = newNode;
        }

        while (nextNode) {
            int gcd = GreatestCommonDivisors(curr->val, nextNode->val);
            ListNode* newNode = new ListNode(gcd);

            newNode->next = nextNode;
            curr->next = newNode;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};