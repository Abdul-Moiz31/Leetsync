class Solution {
public:
    bool isPalindrome(int n) {
        long long rev_num = 0;
        long long N = n;
        while (n > 0) {
            int digit = n % 10;
            n =n/10;
            rev_num = rev_num * 10 + digit;
            
        }
        if (N == rev_num) {
                return true;
            } else {  
        return false;
        }
    }
};