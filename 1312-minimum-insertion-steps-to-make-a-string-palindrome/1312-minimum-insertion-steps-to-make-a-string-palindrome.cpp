class Solution {
public:
    int ans=0;
    int dp[500][500];
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s.size()-1,s);
    }
    int fun(int i,int j,string& s){
        if(i>=j) return 0;
        
        int x=0,y=0,z=0;
        
        if(s[i]==s[j]){
            return fun(i+1,j-1,s);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        x=fun(i+1,j-1,s)+2;
        y=fun(i+1,j,s)+1;
        z=fun(i,j-1,s)+1;
        
        return dp[i][j] = min(x,min(y,z));
    }
};