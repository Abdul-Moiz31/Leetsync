class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        int n = a.size();
        double w = a[0][1];
        int f = a[0][0] + a[0][1];

        for (int i = 1; i < n; ++i) {
            int c = a[i][0];
            int t = a[i][1];

            int s = max(c, f);
            int e = s + t;
            f = e;
            w += e - c;
        }

        return w / n;
    }
};
