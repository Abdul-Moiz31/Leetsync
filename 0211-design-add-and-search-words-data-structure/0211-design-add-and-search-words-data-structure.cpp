struct Node {
    Node* links[26];
    bool flag = false;

    // Check if character already exists in the links
    bool containkey(char ch) { return (links[ch - 'a'] != NULL); }

    // Create a new node for the character
    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    // Get the node corresponding to the character
    Node* get(char ch) { return links[ch - 'a']; }

    // Mark the end of a word
    void setEnd() { flag = true; }

    // Check if it's the end of a word
    bool isEnd() { return flag; }
};

class WordDictionary {
private:
    Node* root;

    // Helper function to handle '.' wildcard during search
    bool searchHelper(string& word, int index, Node* node) {
        if (index == word.length()) return node->isEnd();

        char ch = word[index];
        if (ch == '.') {
            // try all possible paths
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != NULL) {
                    if (searchHelper(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (!node->containkey(ch)) return false;
            return searchHelper(word, index + 1, node->get(ch));
        }
    }

public:
    WordDictionary() { 
        root = new Node(); // initialize root node
    }

    // Adds a word into the data structure
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containkey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(); // mark end of the word
    }

    // Returns if the word is in the data structure (supports '.')
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
