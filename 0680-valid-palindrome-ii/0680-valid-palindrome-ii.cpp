class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try skipping left character
                int l1 = left + 1;
                int r1 = right;
                while (l1 < r1 && s[l1] == s[r1]) {
                    l1++;
                    r1--;
                }

                // Try skipping right character
                int l2 = left;
                int r2 = right - 1;
                while (l2 < r2 && s[l2] == s[r2]) {
                    l2++;
                    r2--;
                }

                return l1 >= r1 || l2 >= r2;
            }
            left++;
            right--;
        }

        return true;
    }
};
