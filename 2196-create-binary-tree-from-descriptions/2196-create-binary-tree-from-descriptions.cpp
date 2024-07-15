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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int , TreeNode*>mp;
        unordered_map<int,int>p , c;
        for(int i =0 ; i<d.size() ; i++){
            if(mp.find(d[i][0])==mp.end()){
                TreeNode* create = new TreeNode(d[i][0]);
                mp[d[i][0]] = create;
            }
            if(mp.find(d[i][1])==mp.end()){
                TreeNode* create = new TreeNode(d[i][1]);
                mp[d[i][1]] = create;
            }
            if(d[i][2])
                mp[d[i][0]] -> left=mp[d[i][1]];
             else 
                mp[d[i][0]] -> right=mp[d[i][1]];
                p[d[i][0]]++;
                c[d[i][1]]++;
        }
        TreeNode* ans;
        for(auto it:mp){
            if(p.find(it.first) != p.end() && c.find(it.first) == c.end()){
                ans=it.second;
                break;
            }
        }
        return ans;


    }
};