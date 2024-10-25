class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(),folders.end());
        vector<string>ans;
        set<string>st;
        for(auto folder:folders){
             string parent="";
             int i=0;
            for(;i<folder.size();i++){
                if(folder[i]=='/'&&parent.size()>0){
                    if(!st.empty()&&st.find(parent)!=st.end())break;
                }
                parent+=folder[i];
            }
            if(i==folder.size()){
                st.insert(folder);
                ans.push_back(folder);
            }
        }
        return ans;
    }
};