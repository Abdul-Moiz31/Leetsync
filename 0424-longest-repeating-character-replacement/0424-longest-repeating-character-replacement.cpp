class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        int maxFre = 0;
        vector<int> hash(26 , 0);
        for(int right = 0 ; right < s.size() ; right++){
            hash[s[right] - 'A']++;
            maxFre = max(maxFre , hash[s[right] - 'A']);
            if((right - left + 1) - maxFre > k){
                hash[s[left] - 'A']--;
                left++;
            }
            maxLen = max( maxLen , right - left + 1);
        }
        return maxLen;
    }
};