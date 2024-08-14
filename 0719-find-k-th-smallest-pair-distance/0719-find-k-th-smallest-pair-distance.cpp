class Solution {
public:
    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l=0,h=v.back()-v[0];
        while(l<h)
        {
            int m=(h+l)/2;
            int b=0;
            for(int i=0;i<v.size();i++)
            {
                int j=lower_bound(v.begin(),v.end(),(v[i]-m))-v.begin();
                b+=(i-j);
            }
            if(k>b) l=m+1;
            else h=m;
        }
        return l;
    }
};