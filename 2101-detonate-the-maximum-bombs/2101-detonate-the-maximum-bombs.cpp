class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b) {
        int ans=0;
        vector<vector<int>> g(b.size());
        for(int i=0;i<b.size();i++){
            long long u=b[i][0],v=b[i][1],w=b[i][2];
            for(int j=i+1;j<b.size();j++){
                long long x=b[j][0],y=b[j][1],r=b[j][2];
                long long a=(x-u)*(x-u) + (y-v)*(y-v);
                if(a<=w*w) g[i].push_back(j);
                if(a<=r*r) g[j].push_back(i);
            }
        }
        for(int i=0;i<b.size();i++){
        vector<int> vis(b.size(),0);
            // if(vis[i]) continue;
            int x=fun(g,vis,i,-1);
            ans=max(ans,x);
        }
        return ans;
    }
    int fun(vector<vector<int>>& g,vector<int>& vis,int i,int par){
        vis[i]=1;
        int cnt=1;
        for(int x:g[i]){
            if(x!=par && !vis[x]){
                cnt += fun(g,vis,x,i);
            }
        }
        return cnt;
    }
};