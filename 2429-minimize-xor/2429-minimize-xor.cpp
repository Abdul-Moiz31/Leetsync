class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0, minXor = 0;

        for (int i = 0; i < 32; i++) {
            if ((1 << i) & num2) cnt++;
        }

     
        for (int i = 31; i >= 0; i--) {
            if (cnt <= 0) break;
            if ((1 << i) & num1) {
                minXor |= (1 << i); 
                cnt--;
            }
        }


        for (int i = 0; i < 32; i++) {
            if (cnt <= 0) break;
            if ((minXor & (1 << i)) == 0) { 
                minXor |= (1 << i); 
                cnt--;
            }
        }

        return minXor;
    }
};