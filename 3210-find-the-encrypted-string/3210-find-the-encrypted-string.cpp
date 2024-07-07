class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string res;
        k=k%n;
        for(int i =k ; i<n ;i++){
            res += s[i];
        } 
          for(int i =0 ; i<k;i++){
            res += s[i];
        } 
        return res;
        
    }
};