class Solution {
public:
    int climbStairs(int n) {
        int prev=0;
        int prev2 = 0;
        int curr;
        if(n==1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 3;
        prev2 = 2;
        prev = 3;
        for(int i = 4;i<=n;i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;

    }
};