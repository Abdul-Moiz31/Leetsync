class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int task_based_answer = tasks.size();
        unordered_map<char, int> task_counts;
        int max_count = 0;
        int max_count_tasks = 0;
        for (auto task : tasks) {
            task_counts[task]++;
            if (task_counts[task] > max_count) {
                max_count = task_counts[task];
                max_count_tasks = 1;
            } else if (task_counts[task] == max_count) {
                max_count_tasks++;
            }
        }
        
        int count_based_answer = (max_count - 1) * (n + 1) + max_count_tasks;

        return max(count_based_answer, task_based_answer);
    }
};