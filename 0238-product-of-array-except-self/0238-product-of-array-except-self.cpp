class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int zeroCount = 0;
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
            if (num == 0) {
                zeroCount++;
                continue;
            }
            totalProduct *= num;
        }

        vector<int> result;
        for (int num : nums) {
            if (zeroCount > 1) {
                result.push_back(0);
            } else if (zeroCount == 1) {
                result.push_back(num == 0 ? totalProduct : 0);
            } else {
                result.push_back(totalProduct / num);
            }
        }

        return result;
    }
};