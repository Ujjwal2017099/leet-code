class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size()+s2.size()) return 0;
        dp.resize(s3.size(),vector<vector<int>>(s1.size(),vector<int>(s2.size(),-1)));
        return fun(s1,s2,s3,0,0,0);
    }
    bool fun(string& a,string& b,string& t,int i,int j,int k){
        if(i==a.size() && j==b.size()){
            return 1;
        }
        
        if(i==a.size() ){
            if(t[k]==b[j]) return fun(a,b,t,i,j+1,k+1);
            else return 0;
        }
        if(j==b.size() ){
            if(t[k]==a[i]) return fun(a,b,t,i+1,j,k+1);
            else return 0;
        }
        
        if(t[k]!=a[i] && t[k]!=b[j]) return 0;
        
        if(dp[k][i][j]!=-1) return dp[k][i][j];
        
        bool x=0,y=0;
        
        if(t[k]==a[i]) x=fun(a,b,t,i+1,j,k+1);
        if(t[k]==b[j]) y=fun(a,b,t,i,j+1,k+1);
        
        return dp[k][i][j] = x|y;
    }
};