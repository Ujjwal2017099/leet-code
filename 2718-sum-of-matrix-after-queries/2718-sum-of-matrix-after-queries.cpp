class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long ans=0;
        long long r=n,c=n;
        unordered_map<int,bool> mr;
        unordered_map<int,bool> mc;
        
        for(int i=q.size()-1;i>=0;i--){
            int x=q[i][0];
            int y=q[i][1];
            long long val=q[i][2];
            if(x && mc[y]) continue;
            if(!x && mr[y]) continue;
            
            if(x && r){
                ans += r*val;c--;
                mc[y]=1;
            }
            if(!x && c){
                ans += c*val;r--;
                mr[y]=1;
            }
            
            
        }
        return ans;
    }
};