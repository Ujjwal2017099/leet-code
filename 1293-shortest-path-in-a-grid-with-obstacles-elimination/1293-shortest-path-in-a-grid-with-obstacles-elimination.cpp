class Solution {
public:
    int dp[45][45][1605] = {0};
    int a[2] = {-1,1};
    int shortestPath(vector<vector<int>>& g, int k) {
        queue<vector<int>> q;
        return fun(g,k,0,0,q,0);
    }
    int fun(vector<vector<int>>& g,int k,int i,int j,queue<vector<int>>& q,int s){
        if(i==g.size()-1 and j==g[0].size()-1){
            return s;
        }
        for(int p:a){
            if(p+i<0 or p+i>=g.size()) continue;
            if(g[p+i][j] and k>0 and !dp[p+i][j][k-1]){
                q.push({p+i,j,k-1,s+1});
                dp[p+i][j][k-1]=1;
            }else if(!g[p+i][j] and !dp[p+i][j][k]){
                q.push({p+i,j,k,s+1});
                dp[p+i][j][k] = 1;
            }
        }
        for(int p:a){
            if(p+j<0 or p+j>=g[0].size()) continue;
            if(g[i][p+j] and k>0 and !dp[i][p+j][k-1]){
                q.push({i,p+j,k-1,s+1});
                dp[i][p+j][k-1]=1;
            }else if(!g[i][p+j] and !dp[i][p+j][k]){
                q.push({i,p+j,k,s+1});
                dp[i][p+j][k]=1;
            }
        }
        if(q.empty()) return -1;
        vector<int> v = q.front();q.pop();
        return fun(g,v[2],v[0],v[1],q,v[3]);
    }
};