#pragma GCC optimize("O3", "unroll-loops")

class Solution {
private:
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmallerIndex(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                nextSmallerIndex[i] = st.top();
            st.push(i);
        }
        return nextSmallerIndex;
    }

    vector<int> prevSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmallerIndex(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                prevSmallerIndex[i] = st.top();
            st.push(i);
        }
        return prevSmallerIndex;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;

        vector<int> nextSmallerIndex = nextSmaller(heights);
        vector<int> prevSmallerIndex = prevSmaller(heights);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int width = nextSmallerIndex[i] - prevSmallerIndex[i] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return '$';
}();
