class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int>ans;

        for(int i=0; i<rows;i++){
            int minRow = INT_MAX;
            int minCol = -1;

            for(int j = 0 ; j < cols ; j++){
                if(matrix[i][j] <minRow){
                    minRow = matrix[i][j];
                    minCol = j;
                }
            }
            bool isLucky = true;
            for(int k =0 ; k< rows ; k++){
                if(matrix[k][minCol] > minRow){
                    isLucky = false;
                    break;
                }
            }
            if(isLucky){
                ans.push_back(minRow);
            }
        }
        return ans;
    }
};