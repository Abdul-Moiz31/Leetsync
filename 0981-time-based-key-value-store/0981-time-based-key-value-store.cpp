class TimeMap {
public:
    TimeMap() {
        
    }
    map<string,vector<pair<int,string>>>cnt;
    void set(string key, string value, int timestamp) {
        cnt[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &p=cnt[key];
        int l=0,r=p.size()-1;
        string s;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(p[mid].first<=timestamp){
                s=p[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return s;
    }
};