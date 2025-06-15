class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Groups;
        
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());  
            Groups[sortedStr].push_back(s);  
        }
        
        vector<vector<string>> result;
        for (auto& pair : Groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
