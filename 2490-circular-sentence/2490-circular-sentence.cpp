class Solution {
public:
    bool isCircularSentence(string s) {
        int flag = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 2) {
                if (s[i + 1] == ' ' && s[i + 2] != s[i])
                    flag = 0;
            }
        }
        if (s[0] != s[s.size() - 1])
            flag = 0;
        return flag;
    }
};