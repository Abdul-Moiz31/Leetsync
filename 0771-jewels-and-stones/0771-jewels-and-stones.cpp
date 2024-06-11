class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
    
         
         unordered_map<char, char> mp;
         int cnt=0;
         for (auto it:jewels){
             mp[it]=it;
         }
         for (auto it:stones){
             if(mp.find(it)!=mp.end())  cnt++;
            }

        return cnt;
    }
};

//     unordered_map<char, char> mp;

    //     //Methods of Insert 
    //     1->//mp.insert ({key , val})
    //     1->//mp[key] = val 

    //    // [{1 ,a}, {2,b}, {3,c}, {4,d}]
       
    //     //{1 , a} it.begin () value 
    //     //i.end(); it points thr value after the ,ast value 
    //      // Simpel Loop 
    //      for (int i=0; i!=size(); i++)
    //      //Mapped Loop 
    //      for( auto it=mp.begin() ; it!=mp.end(); it++)

    //      sort (s.begin(), s.end())
    //      reverse(s.begin(), s.end())
    //      vector<int> r(s.begin(), s.end())