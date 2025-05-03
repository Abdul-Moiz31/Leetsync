class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return 1 / myPow(x, -n);

        if (n == 0)
            return 1; // Base

        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } // evben

        else {
            return x * myPow(x, n - 1);
        }
    }
};