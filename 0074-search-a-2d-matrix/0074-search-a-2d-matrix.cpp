class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        
        int cols = matrix[0].size();

        vector<int> flat;
        for (auto& row : matrix) {
            for (int num : row) {
                flat.push_back(num);
            }
        }

        int low = 0;
        int high = flat.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (flat[mid] == target){
                return true;}
            else if (flat[mid] < target){
                low = mid + 1;}
            else{
                high = mid - 1;}
        }
        return false;
    }
};