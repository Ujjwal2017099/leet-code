class Solution {
public:
    vector<vector<int>> dp;
    vector<int> d;
    int lengthOfLIS(vector<int>& n) {
        dp.resize(n.size(),vector<int>(n.size(),-1));
        d.resize(n.size(),0);
        int ans=0;
        for(int i=0;i<n.size();i++){
            if(d[i]) continue;
            ans=max(ans,fun(n,i+1,i)+1);
        }
        return ans;
    }
    int fun(vector<int>& n,int i,int l){
        if(i>=n.size()){
            return 0;
        }
        if(dp[l][i]!=-1){
            return dp[l][i];
        }
        if(n[l]>=n[i]){
            return dp[l][i]=fun(n,i+1,l);
        }
        
        dp[l][i] = max(fun(n,i+1,i)+1,fun(n,i+1,l));
        d[i]=1;
        return dp[l][i];
    }
};