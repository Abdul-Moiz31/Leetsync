class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;
        for (char c : s) {
            if (c == '0') zeros++;
            else ones++;
        }
        int maxScore = 0, leftZeros = 0, rightOnes = ones;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') leftZeros++;
            else rightOnes--;
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        return maxScore;
    }
};