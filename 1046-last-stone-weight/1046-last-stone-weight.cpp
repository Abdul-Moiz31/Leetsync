class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x, y;
        priority_queue<int> pq(begin(stones), end(stones));
        while(pq.size() > 1){
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();
            y = y-x; pq.push(y);
        }
        return pq.top();
    }
};