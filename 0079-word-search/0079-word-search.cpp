class Solution {
public:
    bool exist(vector<vector<char>>& b, string w) {
        
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                vector<vector<int>> vis(6,vector<int>(6,0));
                if(b[i][j]==w[0]){
                    bool f = fun(b,w,vis,i,j,1);
                    if(f) return 1;
                }
            }
        }
        return 0;
    }
    bool fun(vector<vector<char>>& b,string w,vector<vector<int>>& vis,int i,int j,int x){
        if(x==w.length()){
            return 1;
        }
        vis[i][j]=1;
        bool f=0;
        if(i+1<b.size() && !vis[i+1][j]){
            if(b[i+1][j]==w[x]){
                f=fun(b,w,vis,i+1,j,x+1);
            }
        } 
        if(f==0 && j+1<b[0].size() && !vis[i][j+1]){
            if(b[i][j+1]==w[x]){
                f=fun(b,w,vis,i,j+1,x+1);
            }
        }
        if(f==0 && j-1>=0 && !vis[i][j-1]){
            if(b[i][j-1]==w[x]){
                f=fun(b,w,vis,i,j-1,x+1);
            }
        }
        if(f==0 && i-1>=0 && !vis[i-1][j]){
            if(b[i-1][j]==w[x]){
                f=fun(b,w,vis,i-1,j,x+1);
            }
        }
        vis[i][j]=0;
        return f;
    }
};