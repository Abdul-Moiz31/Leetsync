class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};