class Solution {
public:
int arr[4][2] = {{0,0},{1,2},{-1,1},{-2,-1}};
long long dp[500005][4]={0};
    int minSideJumps(vector<int>& o) {
        memset(dp,-1,sizeof(dp));
        return fun(o,0,2);
    }
    int fun(vector<int>& o,int i,int l){
        if(i==o.size()-2){
            return 0;
        }

        if(dp[i][l]!=-1) {
            return dp[i][l];
        }

        if(o[i+1]!=l) return dp[i][l]= fun(o,i+1,l);
        
        if(l+arr[l][0]==o[i]) return dp[i][l] = fun(o,i,l+arr[l][1])+1;

        if(l+arr[l][1]==o[i]) return dp[i][l] = fun(o,i,l+arr[l][0])+1;

        return dp[i][l] = min(fun(o,i,l+arr[l][0]),fun(o,i,l+arr[l][1]))+1;

    }
};