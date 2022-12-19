class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        vector<int> par(n,-1);
        for(auto it:e){
            int u=it[0],v=it[1];
            Union(par,u,v);
        }
        int a = find(par,s);
        int b = find(par,d);
        return a==b;
    }
    void Union(vector<int>& par,int a,int b){
        int x = find(par,a);
        int y = find(par,b);
        
        if(x==y) return;
        
        if(par[x]<par[y]){
            par[x]+=par[y];
            par[y] = x;
        }else{
            par[y]+=par[x];
            par[x] = y;
        }
    }
    int find(vector<int>& par,int a){
        if(par[a]<0) return a;
        return par[a] = find(par,par[a]);
    }
};