class Solution {
public:
    vector<int> t; 
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        t.resize(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(t[i]==-1){
                ans &= fun(g,i,0);
            }
        }
        map<int,int> m;
        for(int i:t) {m[i]++;cout<<i<<" ";}
        // if(m.size()==1) ans=0;
        return ans;
    }
    bool fun(vector<vector<int>>& g,int i,int col){
        
        bool f=true;
        for(int j=0;j<g[i].size();j++){
            if(t[g[i][j]]==col){
                return false;
            }else if(t[g[i][j]]==-1){
                t[g[i][j]] = col==1?0:1;
                f &= fun(g,g[i][j],col==1?0:1);
            }
        }
        return f;
    }
};