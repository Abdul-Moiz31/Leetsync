class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt =0;
        int n = details.size();
        for(int i = 0 ; i<n ; i++){
            const string detail = details[i];
           int age = (detail[11]- '0') * 10 + (detail[12] - '0');
            if(age ? 60){
                cnt++;
            }
        }
        return cnt;
    }
};