class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        set<int> st;
        for(int i=0;i<n;i++) st.insert(i);
        for(vector<int> t:p){
            int a=t[0],b=t[1];
            if(b==a) return {};
            set<int>::iterator it = st.find(a);
            if(it!=st.end()) st.erase(it);
            g[b].push_back(a);
        }
        vector<int> vis(n,0);
        for(int i:st){
            bool f = fun(g,vis,i);
            if(!f) return {};
        }
        if(ans.size()!=n) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool fun(vector<vector<int>>& g,vector<int>& vis,int i){
       if(vis[i]==1) return 0;
        // n--;
        if(vis[i]==0){
            vis[i]=1;
            
            bool f=1;
            for(int x:g[i]){
                f &= fun(g,vis,x);
                if(f==0) return 0;
            }
        }
        if(vis[i]!=2)ans.push_back(i);
        vis[i] = 2;
        return 1;
    }
};