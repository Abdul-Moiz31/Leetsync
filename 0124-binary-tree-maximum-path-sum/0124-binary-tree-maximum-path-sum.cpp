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
    int maxPathSum1(TreeNode* root  , int &maxi){
        if(root==nullptr) return 0;
        
        int lSum = max(0 , maxPathSum1(root->left , maxi));
        int rSum = max(0 , maxPathSum1(root->right , maxi));
        maxi = max(maxi , lSum + rSum + root->val);
        return max(lSum  , rSum) + root->val ;
        
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSum1(root , maxi);
        return maxi;
    }
};