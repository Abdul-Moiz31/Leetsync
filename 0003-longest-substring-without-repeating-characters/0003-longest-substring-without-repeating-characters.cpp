class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            int windowSize = right - left + 1;
            maxLen = max(maxLen, windowSize);
        }
        return maxLen;
    }
};