class Solution {
public:
    vector<int> dp;
    int deleteAndEarn(vector<int>& n) {
        dp.resize(10001,-1);
       sort(n.begin(),n.end());
        return fun(n,0);
    }
    int fun(vector<int>& n,int i){
        if(i==n.size()){
            return 0;
        }
        if(dp[n[i]]!=-1) return dp[n[i]];
        int sm=n[i];
        int x=n[i];
        int t=i;
        while(i+1<n.size() && n[i+1]==n[i]){
            i++;
            sm+=n[i];
        }
        int in=i+1;
        while(in<n.size() && n[in]==x+1){
            in++;
        }
        
        return dp[x] = max(fun(n,in)+sm,fun(n,i+1));
    }
};