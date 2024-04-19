class Solution {
public:
    vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1}};
    int numIslands(vector<vector<char>>& g) {
        int cnt=0;
        
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='1'){
                    // cout<<'1';
                    fun(g,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void fun(vector<vector<char>>& g,int i,int j){
        queue<vector<int>> q;
        q.push({i,j});
        g[i][j]='0';
        while(q.size()){
            vector<int> x=q.front();q.pop();
            int u=x[0],v=x[1];
            for(vector<int> y:d){
                if(u+y[0]>=0 && u+y[0]<g.size() && v+y[1]>=0 && v+y[1]<g[0].size() && g[u+y[0]][v+y[1]]=='1'){
                    q.push({u+y[0],v+y[1]});
                    g[u+y[0]][v+y[1]]='0';
                }   
            }
        }
    }
};