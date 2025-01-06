class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v(boxes.size(), 0); 
        
        for (int i = 0; i < boxes.size(); i++) {
            int x = 0;
            for (int j = 0; j < boxes.size(); j++) {
                if (boxes[j] == '1') { 
                    x += abs(i - j); 
                }
            }
            v[i] = x; 
        }

        return v;
    }
};