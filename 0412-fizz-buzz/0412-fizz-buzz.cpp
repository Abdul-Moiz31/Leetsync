class Solution {
public:
    vector<string> fizzBuzz(int n) {
       vector<string> result;
       for(int i=1 ; i<=n ; i++){
           if(i%3 == 0 && i%5== 0){
             result.push_back("FizzBuzz");
           } else if (i%3 == 0){
             result.push_back("Fizz");
           } else if (i%5 == 0){
           result.push_back("Buzz");
           } else {
              result.push_back(to_string(i));
           }
       }
        return result; 

    }
};  


// ["1","2","Fizz"]
// intput = {1 , 2 , 3}



// Input: n = 3 
// {"1" , "2" , "3"};
// i%3 == 0 && i%5 == 0
// return "FizzBuzz"
// {"1" , "2" , "Fizz("};
// (i%3 == 0)
// return "Fizz"
// Input: n = 5
// nums { 1, 2 , 3 , 4 , 5}
// nums { 1, 2 , "Fizz" , 4 , "Buzz"}




