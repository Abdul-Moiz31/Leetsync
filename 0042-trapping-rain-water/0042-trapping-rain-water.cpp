class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size() , ans = 0;
        for (int i = 0 ; i < n ; i++){
            while(!st.empty() and height[st.top()] < height[i]){
                int cur =st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int diff = i -st.top()-1;
                ans += (min(height[st.top()], height[i]) - height[cur]) * diff;
            }
            st.push(i);
        }
        return ans;
    }
};