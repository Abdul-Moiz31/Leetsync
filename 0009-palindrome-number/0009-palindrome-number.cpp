class Solution {
public:
    bool isPalindrome(int x) {
        long r = 0;
        long  dup = x;
        while(x>0){
            int ld = x % 10;
            r = r * 10 + ld;
            x = x/10;
        }
        if(dup == r )
            return true;
         else 
            return false;
    }
};