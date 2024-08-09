class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       
     for( int i = s.size()-1 ; i>=0 ; i--){
      if(i==0)
      return false;
     string sub = s.substr(0,i);
        if(s + sub == sub +s)
        return true;
     }
     return false;
    }
};
