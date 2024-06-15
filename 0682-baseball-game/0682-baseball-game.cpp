class Solution {
public:
    int calPoints(vector<string>& op) {
        stack <int>s;
        for(int i =0 ; i<op.size() ;i++){
            if(op[i] == "+"){
                int top = s.top();
                s.pop();
                int newtop = top + s.top();
                s.push(top);
                s.push(newtop);
            } else if(op[i] == "C"){
                s.pop();
            }else if(op[i] == "D"){
                s.push(2* s.top());
            } else {
                s.push(stoi(op[i]));
            }
        }
        int sum = 0;
        while (!s.empty()) {
            sum +=s.top();
            s.pop();
        }
        return sum;
        }
};