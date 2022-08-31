class Solution {
public:
    vector<vector<int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<bool>> a(n,vector<bool>(m,0));
        vector<vector<bool>> p(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            fun(h,i,0,h[i][0],a);
            fun(h,i,m-1,h[i][m-1],p);
        }
        for(int i=0;i<m;i++){
            fun(h,0,i,h[0][i],a);
            fun(h,n-1,i,h[n-1][i],p);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] and p[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void fun(vector<vector<int>>& h,int x,int y,int prev,vector<vector<bool>>& t){
        if(x<0 || x==h.size() || y<0 || y==h[0].size()){
            return;
        }
        if(prev > h[x][y] || t[x][y]){
            return;
        }
        // if( x == h.size()-1 || y == h[0].size()-1){
            t[x][y]=1;
        // }
        for(auto i:d){
            int a = i[0],b = i[1];
            fun(h,x+a,y+b,h[x][y],t);
        }
    }
   
};