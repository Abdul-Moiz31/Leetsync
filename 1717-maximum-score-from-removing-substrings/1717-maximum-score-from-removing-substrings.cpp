class Solution {
      int solve(string &s, string prio){
        int n=s.size();
        int cnt=0;
        stack<char>st;
        for(int i=0 ; i<n ;i++){
            if(!st.empty() && s[i]=prio[1] && st.top()=prio[0]){
                st.pop();
                cnt++;
            } else{
                st.push(s[i]);
            } 
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return cnt;
      }
public:
    int maximumGain(string s, int x, int y) {
        string l="";
        string h="";
        if(y>x){
            l="ab";
            h="ba";
            swap(x,y);
        } else {
            l="ba";
            h="ab";
        }
        int a=solve(l , h)*x;
        int b=solve(l , h)*y;
        return a+b;
    }
};