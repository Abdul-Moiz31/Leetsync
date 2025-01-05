class Solution {
public:

    bool is_vowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> answers (queries.size());
        vector<int> prefix (words.size() + 1, 0);

        for (int i = 0; i < words.size(); i++) {
            prefix[i + 1] += prefix[i] + (is_vowel(words[i].front()) and is_vowel(words[i].back()));
        }

        for (int i = 0; i < queries.size(); i++) {
            answers[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }

        return answers;
    }
};