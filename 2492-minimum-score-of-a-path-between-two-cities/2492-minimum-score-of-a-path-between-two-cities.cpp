class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        vector<int> par(n+1,-1);
        for(auto it:r){
            int u = min(it[0],it[1]);
            int v = max(it[0],it[1]);
            Union(par,u,v);
        }
        // for(int i=1;i<=n;i++) cout<<par[i]<<" ";
        //     cout<<endl;
        int ans = INT_MAX;
        for(auto it:r){
            int u = find(min(it[0],it[1]),par);
            if(u==1){
                ans = min(ans,it[2]);
            }
        }
        return ans;
    }
    void Union(vector<int>& par,int a,int b){
        int u = find(a,par);
        int v = find(b,par);
        if(u==v) return;
        if(u<v){
            par[u] += par[v];
            par[v] = u;
        }else{
            par[v] += par[u];
            par[u] = v;
        }
    }
    int find(int x,vector<int>& par){
        if(par[x]<0) return x;
        return par[x]  = par[x] >= 0 ? find(par[x],par) : par[x];
    }
};