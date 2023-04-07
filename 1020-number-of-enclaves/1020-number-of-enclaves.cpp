class Solution {
public:
    int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int numEnclaves(vector<vector<int>>& g) {
       int n=g.size(),m=g[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=1;i<g.size()-1;i++){
            for(int j=1;j<g[0].size()-1;j++){
                if(!vis[i][j] && g[i][j]==1){
                    queue<vector<int>> q;
                    bool f=0;
                    q.push({i,j});
                    int sz=1;
                    while(!q.empty()){
                        int u=q.front()[0],v=q.front()[1];q.pop();
                        vis[u][v]=1;
                        for(int a=0;a<4;a++){
                            int x=d[a][0],y=d[a][1];
                            if(valid(u+x,v+y,n,m) && !vis[u+x][v+y] && g[u+x][v+y]==1){
                                if(u+x==0 || v+y==0 || u+x==n-1 || v+y==m-1){
                                    f=1;
                                }
                                vis[u+x][v+y]=1;
                                sz++;
                                q.push({u+x,v+y});
                            }
                        }
                    }
                    if(!f) ans+=sz;
                }
            }
        }
        return ans;
    }
    bool valid(int u,int v,int n,int m){
        if(u<0 || v<0) return 0;
        if(u>=n || v>=m) return 0;
        
        return 1;
    }
};