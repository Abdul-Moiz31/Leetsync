class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         auto dist = [](const vector<int>& point) {
            return point[0] * point[0] + point[1] * point[1];
        };

        // Max heap to keep k closest points
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto& point : points) {
            int d = dist(point);
            maxHeap.push({d, point});
            if (maxHeap.size() > k) {
                maxHeap.pop();  // Remove the farthest
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};