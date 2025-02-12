
class Solution {
public:
    int findMax(vector<int>& v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;
        for (int i = 0; i < v.size(); i++) {
            totalH += (v[i] + hourly - 1) / hourly; // Efficient integer division
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1, high = findMax(v);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(v, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
