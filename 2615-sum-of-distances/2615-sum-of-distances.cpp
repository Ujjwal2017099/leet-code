class Solution {
public:
    vector<long long> distance(vector<int>& n) {
        vector<long long> ans(n.size(),0);
        map<int,vector<int>> m;
        for(int i=0;i<n.size();i++){
            m[n[i]].push_back(i);
        }
        for(auto& it:m){
            int x=it.first;
            
            vector<int>& a=it.second;
            long long total=0;
            for(int i=0;i<a.size();i++){
                total += (long long)a[i];
            }
            long long prev = 0;
            for(int i=0;i<a.size();i++){
                ans[a[i]] = total-prev-(long long)a[i]*((long long)a.size()-(long long)i) + (long long)a[i]*(long long)i - prev ;
                prev += a[i];
                if(ans[a[i]]<0) {ans[a[i]]=0;}
            }
        }
        return ans;
    }
};