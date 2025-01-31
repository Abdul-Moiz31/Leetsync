/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if (root == nullptr) {
            return arr;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* root = q.front();
                q.pop();
                int index;
                if (flag) {
                    index = i; // For left-to-right, use index 'i'
                } else {
                    index = size - 1 -
                            i; // For right-to-left, use index 'size - 1 - i'
                }
                row[index] = root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            flag = !flag;
            arr.push_back(row);
        }
        return arr;
    }
};