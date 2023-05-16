class Solution {
public:
    vector<int> par;
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        par.resize(n,-1);
        vector<int> cnt(n,0);
        for(vector<int>& x:e){
            int u=x[0],v=x[1];
            Union(u,v);
            int t=find(u);
            cnt[t]+=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=-1*par[i];
            if((par[i]<0 && cnt[i]==(x*(x-1))/2) || par[i]==-1) ans++;
        }
        return ans;
    }
    int find(int a){
        if(par[a]<0) return a;
        return par[a] = find(par[a]);
    }
    void Union(int a,int b){
        int x=find(a);
        int y=find(b);
        
        if(x==y) return;
        if(par[x]<par[y]){
            par[x] += par[y];
            par[y] = x;
        }
        else{
            par[y] += par[x];
            par[x] = y;
        }
    }
};