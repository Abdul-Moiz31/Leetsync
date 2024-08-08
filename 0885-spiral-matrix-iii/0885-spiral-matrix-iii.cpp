class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int top = rStart;
        int bottom = rStart;
        int right = cStart;
        int left = cStart;
        int i = rStart; 
        int j = cStart;
        // ans.push_back({i, j});
        while(ans.size() < (rows*cols)) {
            // Move Right
            while(j < right){
                if(j >=0 && j < cols && i >= 0 && i< rows){
                    ans.push_back({i,j});
                }
                j++;
            }
            right ++;

            //Down
            while (i <bottom){
                if( j >= 0 && j <cols && i>= 0 && i< rows){
                    ans.push_back({i , j});
                }
                i++;
            }

            bottom++;

            //Left
            while (j >left){
                if( j >= 0 && j < cols && i>= 0 && i< rows){
                    ans.push_back({i , j});
                }
                j--;
            }

            left--;

            //top
            while (j >top){
                if( j >= 0 && j < cols && i>= 0 && i< rows){
                    ans.push_back({i , j});
                }
                i--;
            }
            top--;
            
        }
        return ans;
    }
};