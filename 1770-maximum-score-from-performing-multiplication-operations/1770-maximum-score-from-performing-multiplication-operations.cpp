
int dp[100005][1005];
class Solution {
public:
    int maximumScore(vector<int>& n, vector<int>& m) {
        for(int i=0;i<n.size();i++){
            for(int j=0;j<m.size();j++){
                dp[i][j] = INT_MIN;
            }
        }
        return fun(n,m,0,n.size()-1,0);
    }
    int fun(vector<int>& n,vector<int>& m,int s,int e,int i){
        if(i == m.size()) return 0;
        if(dp[e][s] != INT_MIN) return dp[e][s];
        
        int a = fun(n,m,s+1,e,i+1) + n[s]*m[i];
        int b = fun(n,m,s,e-1,i+1) + n[e]*m[i];
        
        return dp[e][s] = max(a,b);
    }
};