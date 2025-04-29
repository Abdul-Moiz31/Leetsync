class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty())
            return "";

        vector<int> hashS(256, 0);

        vector<int> hashT(256, 0);

        for (int i = 0; i < t.size(); i++) {
            hashT[t[i]]++;
        }
        int left = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int sIndex = 0;
        for (int right = 0; right < s.size(); right++) {
            hashS[s[right]]++;

        if(hashT[s[right]] > 0 && hashS[s[right]] <= hashT[s[right]]){
            cnt++;
        }

        while (cnt == t.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                sIndex = left;
            }
            hashS[s[left]]--;
                    if(hashT[s[left]] > 0 && hashS[s[left]] < hashT[s[left]]){
                        cnt--;
                    }
                    left++;
        }
        }
        if (minLen == INT_MAX) {
            return ""; 
        } else {
            return s.substr(sIndex, minLen); 
        }
    }
};