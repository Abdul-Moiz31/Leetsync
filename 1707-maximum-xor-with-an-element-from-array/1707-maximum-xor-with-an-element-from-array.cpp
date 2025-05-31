struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int x) {
        Node* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int opp = 1 - bit;
            if (node->containsKey(opp)) {
                maxXor |= (1 << i);
                node = node->get(opp);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> offlineQueries;
        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> result(queries.size(), -1);
        int index = 0;

        for (auto &q : offlineQueries) {
            int m = q.first;
            int x = q.second.first;
            int queryIndex = q.second.second;

            while (index < nums.size() && nums[index] <= m) {
                trie.insert(nums[index]);
                index++;
            }

            if (index != 0) {
                result[queryIndex] = trie.getMax(x);
            }
        }

        return result;
    }
};
