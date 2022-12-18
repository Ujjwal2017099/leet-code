class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> dp(n+1,-1);
        for(int i=n-1;i>=0;i--){
            int j=i+1;
            while(j<n && j!=-1 && t[j] <= t[i]) j = dp[j];
            if(j<n && j!=-1) dp[i] = j;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(dp[i]==-1) ans[i] = 0;
            else ans[i] = dp[i]-i;
        }
        return ans;
    }
};