class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        if(p.empty()) return 1;
        vector<vector<int>> g(n);
        set<int> st;
        for(int i=0;i<n;i++) st.insert(i);
        for(vector<int> t:p){
            int a=t[0],b=t[1];
            if(b==a) return 0;
            set<int>::iterator it = st.find(b);
            if(it!=st.end()) st.erase(it);
            g[a].push_back(b);
            // g[b].push_back(a);
        }
        vector<int> vis(n,0);
        bool f=1;
        
        for(int i:st){
            f &= fun(g,vis,i,n);
            // cout<<i<<" ";
            if(f==0) return f;
        }
        if(n>0) return 0;
        // cout<<n;
        return f;
    }
    bool fun(vector<vector<int>>& g,vector<int>& vis,int i,int& n){
        if(vis[i]==1) return 0;
        n--;
        if(vis[i]==0){
            vis[i]=1;
            
            bool f=1;
            for(int x:g[i]){
                f &= fun(g,vis,x,n);
                if(f==0) return 0;
            }
        }
        vis[i] = 2;
        return 1;
    }
};