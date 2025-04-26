class Solution {
public:
    bool validPalindrome(string s) {
        int left= 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
              int left1 = left+1;
              int right1 = right;
              int left2 = left;
              int right2 = right -1;
              while(left1 <right1 && s[left1] == s[right1]){
                left1++;
                right1--;
              } 
              while(left2 <right2 && s[left2] == s[right2]){
                left2++;
                right2--;
              } 
              return left1 >= right1 || left2 >= right2;
            
            }
            left++;
            right--;

        }
        return true;
    }
};