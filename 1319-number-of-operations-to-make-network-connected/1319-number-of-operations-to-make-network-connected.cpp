class Solution {
public:
    vector<vector<int>> g;
    vector<int> group;
    vector<bool> vis;
    int makeConnected(int n, vector<vector<int>>& con) {
        g.resize(n);
        vis.resize(n,0);
        for(auto i:con){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int a=get_noConnection(i);
                group.push_back(a);
                if(a>1)mx++;
            }
        }
        int ch = 0;
        for(int i:group) {
            ch+=i-1;
        }
        if(con.size() - ch < group.size()-mx) return -1;
        return group.size()-1;
    }
    int get_noConnection(int x){
        if(vis[x]) return 0;
        
        vis[x] = 1;
        int ans = 1;
        
        for(int i:g[x]){
            if(!vis[i]){
                ans += get_noConnection(i);
            }
        }
        return ans;
    }
};