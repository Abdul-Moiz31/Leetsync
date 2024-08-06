class Solution {
public:
    int largestAltitude(vector<int>& gain) {
          int currAlt = 0;
        int highAlt = 0;

        for (int i = 0; i < gain.size(); ++i) {
            currAlt += gain[i];
            highAlt = max(highAlt, currAlt);
        }

        return highAlt;
    }
};
