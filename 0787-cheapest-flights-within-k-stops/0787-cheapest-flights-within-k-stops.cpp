class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        int ans=1e7;
        vector<vector<int>> g(n);
        map<vector<int>,int> w;
        for(auto it:f){
            g[it[0]].push_back(it[1]);
            w[{it[0],it[1]}] = it[2];
        }
        vector<int> vis(n,0);
        queue<vector<int>> q;
        q.push({src,0,0});
        while(!q.empty()){
            vector<int> x=q.front();q.pop();
            if(x[1]>k+1) continue;
            if(x[0]==dst){
                ans=min(ans,x[2]);
                continue;
            }
            for(int i:g[x[0]]){
                if(!vis[i] || vis[i]>x[2]+w[{x[0],i}]){
                    q.push({i,x[1]+1,x[2]+w[{x[0],i}]});
                    vis[i]=x[2]+w[{x[0],i}];
                }
            }
        }
        if(ans==1e7) return -1;
        return ans;
    }
};