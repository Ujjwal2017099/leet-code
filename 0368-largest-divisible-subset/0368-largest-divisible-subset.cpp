class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& n) {
        sort(n.begin(),n.end());
        int mx=0;
        vector<vector<int>> dp(n.size()+1,vector<int>(n.size(),0));
        for(int i=0;i<n.size();i++){
            for(int j=i+1;j<n.size();j++){
                if(n[j]%n[i]==0) dp[i+1][j]=max(dp[i][i]+1,dp[i][j]);
                else dp[i+1][j]=dp[i][j];
                
                if(dp[i+1][j]>=dp[mx][mx]){
                    mx=j;       
                }
            }
        }
        
//         for(int i=0;i<n.size();i++){
//             for(int j=0;j<n.size();j++){
                
//                 // cout<<dp[i+1][j]<<" ";
//             }
//             // cout<<endl;
//         }
        vector<int> ans;
        ans.push_back(n[mx]);
        int prev=mx;
        while(mx>0){
            if(ans.back()%n[mx-1]==0 && dp[mx][prev]>dp[mx-1][prev]){
                prev=mx-1;
                ans.push_back(n[prev]);
            }
            mx--;
        }
        // if(n[0])
        return ans;;
    }
    
};