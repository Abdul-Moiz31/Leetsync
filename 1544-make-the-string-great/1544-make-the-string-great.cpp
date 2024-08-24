class Solution {
public:
    string makeGood(string s) {

        vector<char> st;

        st.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) {
            char topval = st.back();

            if (!st.empty() && abs(topval - s[i]) == 32) {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }
        string ans(st.begin(), st.end());

        return ans;
    }
};