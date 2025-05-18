class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        if (N == 0)
            return 1; // Base

        if (N % 2 == 0) {
            return myPow(x * x, N / 2);
        } // evben

        else {
            return x * myPow(x, N - 1);
        }
    }
};