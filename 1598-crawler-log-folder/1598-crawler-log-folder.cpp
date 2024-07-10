class Solution {
public:
    int minOperations(vector<string>& log) {
        int depth = 0;

        for(int i = 0 ; i<log.size() ; i++){
            if(log[i] =="./"){
                continue;
            } else if(log[i] == "../") {
            if(depth>0) depth--;
        } else {
             depth++;
        }
        }
        return depth;
    }
};