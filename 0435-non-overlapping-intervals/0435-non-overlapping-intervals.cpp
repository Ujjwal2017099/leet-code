class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        
        int ans=0;
        int mx=INT_MIN;
        for(vector<int> v:i){
            if(v[0]>=mx){
                ans++;
                mx=v[1];
            }
        }
        return i.size()-ans;
    }
};