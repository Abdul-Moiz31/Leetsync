class Solution {
public:
    struct node{
        unordered_map <char,node*> child;
        bool end;
    };
    node *root;
    bool subFolder(string s){
        node *curr = root;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(c == '/' and curr -> end)
                return true;
            if(curr -> child[c] == nullptr)
                curr -> child[c] = new node();
            curr = curr -> child[c];
        }
        curr -> end = true;
        return false; 
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end()); // sort for processing lexicographically
        root = new node();
        vector <string> ans;
        for(string &s : folder)
            if(not subFolder(s))
                ans.push_back(s);
        return ans;
    }
};