class Solution {
public:
    vector<vector<int>> d = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> findFarmland(vector<vector<int>>& l) {
        vector<vector<int>> ans;
        
        
        for(int i=0;i<l.size();i++){
            for(int j=0;j<l[0].size();j++){
                if(l[i][j]){
                    fun(l,ans,i,j);
                }
            }
        }
        
        return ans;
    }
    void fun(vector<vector<int>>& l,vector<vector<int>>& ans,int i,int j){
        queue<vector<int>> q;
        
        q.push({i,j});
        
        l[i][j]=0;
        
        vector<int> r=q.front();
        while(q.size()){
            vector<int> x = q.front();q.pop();
            for(vector<int> it:d){
                int u = it[0]+x[0],v=it[1]+x[1];
                
                if(u>=0 && u<l.size() && v>=0 && v<l[0].size() && l[u][v]){
                    if(r[0]<=u && r[1]<=v){
                        r = {u,v};
                    }
                    // if(v==2 && u==2){cout<<r[0]<<" "<<r[1];}
                    q.push({u,v});
                    l[u][v]=0;
                }
            }
        }
        ans.push_back({i,j,r[0],r[1]});
    }
};