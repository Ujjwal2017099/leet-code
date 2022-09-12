const int N = 1e5+1;
class Solution {
public:
    int dp[N][2][3] = {0};
    int fun(vector<int>& p,int b,int i,int ch){
        if(i==p.size() or ch == 0){
            return 0;
        }
        if(dp[i][b][ch] != -1){
            return dp[i][b][ch];
        }
        int ans = 0;
        if(b){
            ans += max(fun(p,0,i+1,ch) - p[i],fun(p,1,i+1,ch));
        }else{
            ans += max(p[i] + fun(p,1,i+1,ch-1),fun(p,0,i+1,ch));
        }
        return dp[i][b][ch] = ans;
    }
    int maxProfit(vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return fun(p,1,0,2);
    }
};