class Solution {
public:
    string multiply(string n1, string n2) {
        int a = n1.size(); 
        int b = n2.size(); 
        string res(a+b, '0');  
        for(int i=a-1; i>=0; i--) {  
            for(int j=b-1; j>=0; j--) {
                int di = (n1[i] - '0') * (n2[j] - '0') + (res[i+j+1]-'0');
                res[i+j+1] = di % 10 + '0';
                res[i+j] += di/10;
            }
        }

        for(int i=0; i<res.size(); i++) {
            if(res[i]!='0') return res.substr(i);
        }
        return "0";

    }
};


