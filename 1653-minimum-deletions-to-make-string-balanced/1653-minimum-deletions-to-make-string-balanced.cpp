class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<int>st;
        int cnt = 0;
        for(int i = 1 ; i<n ; i++){
            if(!st.empty() && (st.top() == 'b' & s[i] == 'a')){
                st.pop();
                cnt++;
            } else{
                st.push(s[i]);
            }
        }
        return cnt;
    }
};