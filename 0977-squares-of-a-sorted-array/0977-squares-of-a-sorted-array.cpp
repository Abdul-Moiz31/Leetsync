class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      for ( int i = 0 ; i<nums.size() ; i++){
        nums[i] = nums[i]*nums[i];
      }
      sort(nums.begin(),nums.end());
      return nums;
    }
};

// [-4,-1,0,3,10]

//  for(int i=0;i<nums.size();i++){
// 		nums[i]=nums[i]*nums[i];
// 	}
// 	sort(nums.begin(),nums.end());
//     i=0 = -4  ; 
//     nums[0]=nums[0]*nums[0];
//     = -4 * -4 = 16 
//    i =1 = -1 
// nums[1]=nums[1]*nums[1];
//  = -1 * -1 = 1
// i = 2 = 0 
// nums[2]=nums[2]*nums[2];
// 0 * 0 = 0
// i = 3 = 3
// nums[3]=nums[3]*nums[3];
// 3* 3 = 9 
// i = 4 = 10
// nums[3]=nums[3]*nums[3];
// 10* 10 = 100
// { 16 , 1 , 0 , 9 , 100 } 
// using namespace std:
// {1 , 16 , 0 , 9 , 100}
// { 0 , 1 , 9 , 16  , 100}
