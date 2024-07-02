class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
    vector<int> arr;
    unordered_map<int , int> um;
    for(auto num :a){
        um[num]++;
    } 
    for(auto num : b){
        if(um[num] >0){
            arr.push_back(num);
            um[num]--;
        }
    }
    return arr;
}
};