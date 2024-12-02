class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        int id=1;
        while(s>>word){
            if(word.find(searchWord) < 1)
            return id;
            id++;
        }
        return -1;
    }
};