class Solution {
public:
    int minTime(int n, vector<vector<int>>& e, vector<bool>& ha) {
        vector<vector<int>> g(n);
        for(auto it:e){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        // queue<vector<int>> q;
        // int ans=0;
        // q.push({0,0});
        // map<int,bool> mp;
        // while(!q.empty()){
        //     vector<int> x = q.front();q.pop();
        //     if(ha[x[0]]){
        //         if(mp[x[1]]) ans++;
        //         else ans += x[1];
        //         mp[x[1]] = 1;
        //     }
        //     for(int i:g[x[0]]){
        //         q.push({i,x[1]+1});
        //     }
        // }
        vector<bool> vis(n,0);
        int ans = fun(g,vis,0,ha,0);
        // cout<<ans;
        return ans*2;
    }
    int fun(vector<vector<int>>& g,vector<bool>& vis,int i,vector<bool>& ha,int s){
        vis[i] = 1;
        if(g[i].empty()){
            if(ha[i]) return s;
            return 0;
        }
        bool f = 0;
        int cnt = 0;
        for(int x:g[i]){
            if(vis[x]) continue;
            int a = fun(g,vis,x,ha,s+1);
            if(a && !f) {cnt+= a;f=1;}
            else if(a && f){cnt+=a-s;}
        }
        if(cnt==0 && ha[i]) cnt = s;
        return cnt ;
    }
};