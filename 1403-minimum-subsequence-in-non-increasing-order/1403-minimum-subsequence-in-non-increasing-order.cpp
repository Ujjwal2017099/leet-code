class Solution {
public:
    vector<int> minSubsequence(vector<int>& n) {
        vector<vector<int>> v;
        int tsm =0 ,sm=0;
        for(int i=0;i<n.size();i++){
            v.push_back({n[i],i});
            tsm += n[i];
        }
        sort(v.begin(),v.end());
        vector<vector<int>> t;
        for(int i=v.size()-1;i>=0;i--){
            if(sm > tsm) break;
            sm += v[i][0];
            tsm -= v[i][0];
            t.push_back(v[i]);
        }
        sort(t.begin(),t.end(),[&](vector<int> a,vector<int> b){
            return a[0] > b[0]; 
        });
        vector<int> ans;
        for(auto it:t){
            ans.push_back(it[0]);
        }
        return ans;
    }
};