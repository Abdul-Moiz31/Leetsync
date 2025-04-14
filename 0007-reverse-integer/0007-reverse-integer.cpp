class Solution {
public:
    int reverse(int x) {
     long long rev_num = 0;
     while(x != 0){
        int lastDigit = x % 10;
        x = x/10;
        rev_num = rev_num * 10 + lastDigit;
        if(rev_num < INT_MIN || rev_num > INT_MAX){
            return 0;
        }
     }   
     return rev_num;
    }
};