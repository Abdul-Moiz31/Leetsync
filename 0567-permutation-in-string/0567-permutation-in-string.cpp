class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<char> hashs1(26, 0);
        vector<char> hashs2(26, 0);
        int s1Len = s1.size();
        int s2Len = s2.size();

        if (s1Len > s2Len)
            return false;

        for (int left = 0; left < s1Len; left++) {
            hashs1[s1[left] - 'a']++;
        }

        for (int right = 0; right < s2Len; right++) {
            hashs2[s2[right] - 'a']++;

            if (right >= s1Len) 
                hashs2[s2[right - s1Len] - 'a']--;

                if (hashs1 == hashs2) {
                    return true;

            }
        }
        return false;
    }
};