class Solution {
public:
    int ans=0;
    vector<int> dp;
    int maxSatisfaction(vector<int>& s) {
        int n=s.size();
        dp.resize(n,-1);
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            ans += (i+1)*s[i];
        }
        fun(s,0,1,0);
        return ans;
    }
    void fun(vector<int>& s,int i,int j,int sum){
        if(i>=s.size()) return;
        if(s[i]>=0) return;
        if(dp[i]!=-1){
            ans = max(ans,dp[i]+sum);
            return;
        }
        int sm=sum;
        int y=j;
        for(int x=i+1;x<s.size();x++){
            sm += (y++)*s[x];
        }
        ans=max(ans,sm);
        dp[i] = sm-sum;
        fun(s,i+1,j,sum);
        fun(s,i+1,j+1,sum+j*s[i]);
    }
};