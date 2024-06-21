class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;

        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {

                int length = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, width * length);
            }
            st.push(i);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;

        if (rows == 0 || cols == 0)
            return 0;

        vector<vector<int>> M(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                M[i][j] = matrix[i][j] - '0';

        int maxArea = largestRectangleArea(M[0]);
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                if (M[i][j] != 0)
                    M[i][j] += M[i - 1][j];
                else
                    M[i][j] = 0;

            maxArea = max(maxArea, largestRectangleArea(M[i]));
        }

        return maxArea;
    }
};