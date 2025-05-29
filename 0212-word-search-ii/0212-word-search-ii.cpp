struct TrieNode {
    TrieNode* children[26];
    string word = ""; // to store word at the end of path

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == NULL)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word; // mark end of word
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char ch = board[i][j];

        if (ch == '#' || node->children[ch - 'a'] == NULL) return;

        node = node->children[ch - 'a'];

        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; // avoid duplicate words
        }

        board[i][j] = '#'; // mark visited

        // explore neighbors
        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, 1, 0, -1 };

        for (int dir = 0; dir < 4; ++dir) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                dfs(board, ni, nj, node, result);
            }
        }

        board[i][j] = ch; // restore character
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (string word : words)
            insert(word); // build trie

        vector<string> result;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
