class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        if (l >= r) return true;
        if (s[l] != s[r]) return false;
        return isPalindrome(s, l + 1, r - 1);
    }

    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    ans = s.substr(i, maxLen);
                }
            }
        }

        return ans;
    }
};
