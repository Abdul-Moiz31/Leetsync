class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto [task, count] : freq) {
            maxHeap.push(count);
        }

        int time = 0;

        while (!maxHeap.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            int tasksProcessed = 0;
            for (int i = 0; i < cycle && !maxHeap.empty(); ++i) {
                int count = maxHeap.top(); maxHeap.pop();
                if (--count > 0) {
                    temp.push_back(count);
                }
                time++;
                tasksProcessed++;
            }

            for (int count : temp) {
                maxHeap.push(count);
            }

            // Add idle time only if there are tasks left
            if (!maxHeap.empty()) {
                time += (cycle - tasksProcessed);
            }
        }

        return time;
    }
};
