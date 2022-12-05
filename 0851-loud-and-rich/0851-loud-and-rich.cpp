class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        int n = q.size();
        if(n==1) return q;
        vector<vector<int>> g(n);
        // vector<int> par(n,-1);
        for(vector<int> t:r){
            int u = t[0],v = t[1];
            // if(!find(g,u,v)){
                g[v].push_back(u);
            // }
            // Union(par,u,v);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            // for(int j=0;j<n;j++){
            //     if(i==j) continue;
                
                // int a = Find(par,i);
                // int b = Find(par,j);
                // if(a!=b){
                //     if(ans[i]!=-1){
                //         ans[i] = q[ans[i]] > q[j] ? j : ans[i];
                //     }else{
                //         ans[i] = q[i] > q[j] ? j : i;
                //     }
                // }
                // else{
                    vector<int> vis(n,0);
                    // int mn = -1;
                    // for(int x:g[i]){
                        int mn = dfs(g,vis,q,i);
                        // if(mn!=-1){
                        //     mn = q[mn] > q[a] ? a : mn;
                        // }else{
                        //     mn = a;
                        // }
                    // }
                    ans[i] = mn;
                // }
            // }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& g,vector<int>& vis,vector<int>& q,int i){
        if(g[i].empty() || vis[i]){
            return i;   
        }
        vis[i] =1;
        int mn = i;
        for(int x:g[i]){
            int a = dfs(g,vis,q,x);
            mn = q[mn] > q[a] ? a : mn;
        }
        return mn;
    }
    bool find(vector<vector<int>>& g,int i,int& tar){
        if(i==tar) return 1;
        if(g[i].empty()) return 0;
        
        for(int x:g[i]){
            bool f = find(g,x,tar);
            if(f) return 1;
        }
        return 0;
    }
    void Union(vector<int>& par,int u,int v){
        int x = Find(par,u);
        int y = Find(par,v);
        
        if(x==y) return;
        if(par[x] < par[y]){
            par[x] += par[y];
            par[y] = x;
        }else{
            par[y] += par[x];
            par[x] = y;
        }
    }
    int Find(vector<int>& par,int x){
        if(par[x]<0) return x;
        return par[x] = par[x]>=0 ? Find(par,par[x]) : par[x];
    }
};