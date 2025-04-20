class Solution {
public:
    bool isPalindrome(int n) {
        long long rev_num = 0;
        long long original = n;
        while(n>0){
            int lastDigit = n% 10;
            n = n/10;
            rev_num = rev_num * 10 + lastDigit;
        }
        if(rev_num == original){
            return true;
        } else {
            return false ;
        }
    }
};