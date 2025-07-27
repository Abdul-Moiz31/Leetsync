class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) freq[card]++;

        for (auto& [card, count] : freq) {
            if (count > 0) {
                for (int i = 1; i < groupSize; ++i) {
                    if (freq[card + i] < count) return false;
                    freq[card + i] -= count;
                }
            }
        }

        return true;
    }
};
