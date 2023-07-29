class Solution {
public:
    vector<vector<int>> vis;
    int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    void solve(vector<vector<char>>& b) {
        vis.resize(b.size(),vector<int>(b[0].size(),0));
        for(int i=0;i<b.size();i++){
            if(b[i][0]=='O')fun(b,i,0);
            if(b[i][b[0].size()-1]=='O') fun(b,i,b[0].size()-1);
        }
        for(int j=0;j<b[0].size();j++){
            if(b[0][j]=='O')fun(b,0,j);
            if(b[b.size()-1][j]=='O')fun(b,b.size()-1,j);
        }
        
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]=='O' && !vis[i][j]) b[i][j]='X';
            }
        }
    }
    void fun(vector<vector<char>>& b,int i,int j){
        // if(i==b.size()-1 || j==b[0].size()-1 || i==0 || j==0) return ;
       
        vis[i][j]=1;
        for(int x=0;x<4;x++){
            int u=d[x][0]+i,v=d[x][1]+j;
            if(ok(u,v,b) && !vis[u][v] && b[u][v]=='O'){
                fun(b,u,v);
            }
        }
        // if(!f) b[i][j]='X';
        
        // return f;
    }
    bool ok(int i,int j,vector<vector<char>>& b){
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size()) return 0;
        return 1;
    }
};