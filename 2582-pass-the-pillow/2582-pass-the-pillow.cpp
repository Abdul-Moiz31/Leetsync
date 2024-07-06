class Solution {
public:
    int passThePillow(int n, int time) {
        int total = time/(n-1);
        bool revdir = (total % 2 != 0);
        if(revdir){
            return n - (time % (n-1));
        } else {
            return time % (n - 1) +1;
        }
    }
};