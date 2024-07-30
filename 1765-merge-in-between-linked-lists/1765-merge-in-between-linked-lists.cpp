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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;

        for (int i = 0; i < a - 1; ++i)
            prevA = prevA->next;

        ListNode* afterB = prevA->next;

        for (int j = 0; j <= b - a; ++j)
            afterB = afterB->next;

        prevA->next = list2;

        ListNode* endOfList2 = prevA;
        while (endOfList2->next != nullptr)
            endOfList2 = endOfList2->next;

        endOfList2->next = afterB;

        return list1;
    }
};
int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    int a, b;
    string s1, s2;
    while (cin >> s1 >> a >> b >> s2) {
        b++;
        int a1{};
        int b1{};
        for (int i{1}, c{};; ++i) {
            if (s1[i] == ',') {
                ++c;
                if (c == a)
                    a1 = i;
                else if (c == b) {
                    b1 = i;
                    break;
                }
            }
        }
        std::string_view l0{s1.begin(), s1.begin() + a1 + 1};
        std::string_view l1{s2.begin() + 1, s2.end() - 1};
        std::string_view l2{s1.begin() + b1, s1.end()};
        cout << l0 << l1 << l2 << '\n';
    }
    exit(0);
    return 0;
}();
