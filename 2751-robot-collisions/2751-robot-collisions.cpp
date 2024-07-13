class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n =positions.size();
        vector<int> in(n), r;
        stack<int> st;
        for(int i =0; i<n ; i++){
            in[i] = i   ;
            }
        sort(in.begin() , in.end() , [&](int lhs, int rhs){
            return positions[lhs] < positions[rhs];
        });
        for(int currin : in){
            if(directions[currin] == 'R'){
                st.push(currin);
            } else{
                while(!st.empty() && healths[currin] > 0){
                    int topin = st.top();
                    st.pop();

                    if(healths[topin] > healths[currin]) {
                        healths[topin] -=1;
                        healths[currin] =0;
                        st.push(topin);
                    } else if ( healths[topin] < healths[currin]){
                        healths[currin] -=1;
                        healths[topin] =0;
                    }else{
                        healths[currin] = 0;
                        healths[topin] = 0;
                    }
                }
            }
        }
        //Collect surviving robots 
       for(int i =0; i<n ; i++){
         if(healths[i] > 0){
            r.push_back(healths[i]);
         }
            }
            return r;
    }
};