class Solution {
public:
    int reverse(int n) {
       long long reverse_num = 0;
       while(n != 0){
        int digit = n % 10;
        n = n/10;
        reverse_num = reverse_num * 10 + digit;
         if (reverse_num < INT_MIN || reverse_num > INT_MAX) {
                return 0;
            }
       }
       return reverse_num;
    }
};