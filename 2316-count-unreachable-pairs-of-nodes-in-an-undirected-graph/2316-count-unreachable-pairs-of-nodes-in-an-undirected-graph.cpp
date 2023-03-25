class Solution {
public:
    vector<int> par;
    long long countPairs(long long n, vector<vector<int>>& e) {
        par.resize(n,-1);
        for(vector<int>& t:e){
            int u=t[0],v=t[1];
            Union(u,v);
        }
        map<int,int> cnt;
        
        for(int i=0;i<n;i++){
            int x=find(i);
            cnt[x]++;
        }
        long long ans=(n*(n-1))/2;
        for(auto& it:cnt){
            long long x=it.second;
            ans -= (x*(x-1))/2; 
        }
        return ans;
    }
    void Union(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y) return;
        
        if(par[x]<par[y]) {par[x]+=par[y];par[y]=x;}
        else {par[y]+=par[x];par[x]=y;}
    }
    int find(int a){
        if(par[a]<0) return a;
        return par[a] = find(par[a]);
    }
};