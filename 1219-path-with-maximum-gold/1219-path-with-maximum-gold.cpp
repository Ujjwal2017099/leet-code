class Solution {
public:
    vector<vector<int>> d={{0,1},{0,-1},{1,0},{-1,0}};
    int getMaximumGold(vector<vector<int>>& g) {
        int ans=0;
        int mx=0;
        for(vector<int> x:g){for(int i:x) mx+=i;}
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]!=0){
                    int x=bfs(g,i,j);
                    ans=max(ans,x);
                    // cout<<x<<" ";
                }
                
                if(ans==mx) break;
            }
            if(ans==mx) break;
        }
        return ans;
    }
    int bfs(vector<vector<int>>& g,int i,int j){
        int temp=g[i][j];
        int y = g[i][j];
        g[i][j]=0;
        for(vector<int> x:d){
            if(ok(g.size(),g[0].size(),x[0]+i,x[1]+j) && g[x[0]+i][x[1]+j]){
                int z = bfs(g,x[0]+i,x[1]+j);
                
                temp = max(temp,y+z);
            }
        }
        
        g[i][j]=y;
        
        return temp;
    }
    
    bool ok(int n,int m,int i,int j){
        if(i>=n || i<0) return 0;
        if(j>=m || j<0) return 0;
        
        return 1;
    }
};