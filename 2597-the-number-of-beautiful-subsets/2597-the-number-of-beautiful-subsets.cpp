class Solution {
public:
    int dp[21];
    int beautifulSubsets(vector<int>& n, int k) {
        // memset(dp,-1,sizeof(dp));
        unordered_map<int,bool> s;
        return dfs(n,0,k,s);
    }
    int dfs(vector<int>& n,int i,int k,unordered_map<int,bool>& s){
        if(i==n.size()){
            return 0;
        }
        // if(dp[i]!=-1) return dp[i];
        int x=dfs(n,i+1,k,s);
        int y=0;
        if(!s[n[i]+k] && !s[n[i]-k]){
            s[n[i]]=1;
            y = dfs(n,i+1,k,s)+1;
            s[n[i]]=0;
        }
        return x+y;
    }
};