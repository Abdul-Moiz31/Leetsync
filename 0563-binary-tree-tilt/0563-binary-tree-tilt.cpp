/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int findTree(TreeNode *root){
        if(!root)
            return 0;
            int sum = root->val;
            sum += findTree(root->left) + findTree(root->right);
            return sum; 
                
            }

        int findTilt(TreeNode* root) {
            if(root == NULL)
                return 0;

                int sum = abs(findTree(root->left) - findTree(root->right));
                sum += findTilt(root->left) + findTilt(root->right);
                return sum;


    }
};