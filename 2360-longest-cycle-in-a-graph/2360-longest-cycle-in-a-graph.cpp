class Solution {
public:
    vector<int> vis;
    int longestCycle(vector<int>& e) {
        int n=e.size();
        vis.resize(n,0);
                vector<int> dp(n,0);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int x=dfs(e,i,0,dp);
                ans=max(ans,x);
                // cout<<ans<<" "<<i<<endl;
            }
        }
        return ans==0 ? -1:ans;
    }
    int dfs(vector<int>& e,int i,int s,vector<int>& dp){
        if(vis[i]==2){
            return -1;
        }
        if(dp[i]) {
            vis[i]=2;
            return s-dp[i];
        }
        if(e[i]==-1){
            return -1;
        }
        vis[i]=1;
        dp[i]=s;
        int x=dfs(e,e[i],s+1,dp);
        dp[i]=0;
        if(x!=-1) vis[i]=2;
        return x;
    }
};