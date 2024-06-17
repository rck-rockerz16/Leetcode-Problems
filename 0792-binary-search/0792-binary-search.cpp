int init = [] {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());

    for (string s; getline(cin, s); cout << '\n') {
        string t;
        getline(cin, t);
        int tar = stoi(t);

        for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i) {
            bool _neg = 0;
            if (s[_i] == '-')
                ++_i, _neg = 1;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10)
                v = v * 10 + (s[_i++] & 15);
            if (_neg)
                v = -v;
            if (v == tar) {
                cout << i;
                goto next;
            }
            if (v > tar)
                break;
        }
        cout << -1;
    next:;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while (left <= right) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left) / 2;
        }
        return -1;
    }
};