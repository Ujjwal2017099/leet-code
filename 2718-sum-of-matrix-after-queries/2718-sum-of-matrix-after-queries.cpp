class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long ans=0;
        long long r=n,c=n;
        
        vector<vector<bool>> mp(2,vector<bool>(n,0));
        
        for(int i=q.size()-1;i>=0;i--){
            if(!r && !c) break;
            int x=q[i][0];
            int y=q[i][1];
            long long val=q[i][2];
            if(mp[x][y]) continue;
            
            if(x && r){
                ans += r*val;c--;
            }
            if(!x && c){
                ans += c*val;r--;
            }
            
            mp[x][y]=1;
        }
        return ans;
    }
};