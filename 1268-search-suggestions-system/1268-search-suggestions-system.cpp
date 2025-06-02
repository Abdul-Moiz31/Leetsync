struct Node {
    Node* links[26];
    vector<string> suggestions;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void addSuggestion(string word) {
        if (suggestions.size() < 3) {
            suggestions.push_back(word);
        }
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->addSuggestion(word);
        }
    }

    vector<vector<string>> getSuggestions(string word) {
        vector<vector<string>> result;
        Node* node = root;
        for (char ch : word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
                result.push_back(node->suggestions);
            } else {
                // For the remaining characters, push empty suggestions
                while (result.size() < word.size()) {
                    result.push_back({});
                }
                break;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie trie;
        for (string& product : products) {
            trie.insert(product);
        }
        return trie.getSuggestions(searchWord);
    }
};
