class Solution {
public:
    int minSwaps(string s) {
        int br = 0;
        
        for(auto c : s) {
            if (c == '[') 
                br++; 
            else if (br > 0) 
                br--; 
        }
        
        return (br + 1) / 2;
    }
};