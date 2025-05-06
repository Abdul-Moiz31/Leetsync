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
    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }
        int leftSame = isSame(p->left, q->left);
        int rightSame = isSame(p->right, q->right);
        return p->val == q->val && leftSame && rightSame;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }
        if (root->val == subRoot->val && isSame(root, subRoot)) {
            return true;
        }
        int leftsubtree = isSubtree(root->left, subRoot);
        int righttsubtree = isSubtree(root->right, subRoot);

        return leftsubtree || righttsubtree;
    }
};