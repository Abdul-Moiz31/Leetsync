class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>m;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(') { 
                m.push(i);
                }
            else if(s[i]==')') {
            int start = m.top();
            m.pop();
            reverse(s.begin() + start + 1 , s.begin() + i);
            }
        }
        string ans="";
        for(int i=0 ; i<s.size(); i++){
            if(s[i] != ')' & s[i] != '(') {
                ans.push_back(s[i]);
                }
        }
        return ans;
    }
};