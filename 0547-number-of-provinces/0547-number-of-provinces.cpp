class Solution {
public:
    int findCircleNum(vector<vector<int>>& c) {
        vector<int> par(c.size(),-1);
        for(int i=0;i<c.size();i++){
            for(int j=0;j<c.size();j++){
                if(i!=j and c[i][j]){
                    Union(i,j,par);
                }
            }
        }
        int cnt=0;
        for(int i:par){
            if(i<0) cnt++;
        }
        return cnt;
    }
    int find(int a,vector<int>& par){
        if(par[a]<0) return a;
        return find(par[a],par);
    }
    void Union(int a,int b,vector<int>& par){
        int x=find(a,par);
        int y=find(b,par);
        if(x!=y){
            par[x]+=par[y];
            par[y]=x;
        }
    }
};