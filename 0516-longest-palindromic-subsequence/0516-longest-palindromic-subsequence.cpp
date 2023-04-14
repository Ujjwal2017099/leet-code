class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,-1));
        return fun(s,0,n-1);
    }
    int fun(string& s,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(s[i]==s[j]) return dp[i][j] = 2+fun(s,i+1,j-1);
        else return dp[i][j] = max(fun(s,i+1,j),fun(s,i,j-1));
    }
};