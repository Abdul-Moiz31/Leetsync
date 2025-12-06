class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int n = people.size();
        int left = 0;
        int right = n - 1;
        int cnt=0;

        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                left++;
                right--;
            } else {
                right--;
            }
            cnt++;
        }
        return cnt;

    }
};