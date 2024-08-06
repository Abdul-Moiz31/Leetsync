class Solution {
public:
    int largestAltitude(vector<int>& gain) {
          int curr = 0;
        int high = 0;

        for (int i = 0; i < gain.size(); ++i) {
            curr += gain[i];
            high = max(high, curr);
        }

        return high;
    }
};
