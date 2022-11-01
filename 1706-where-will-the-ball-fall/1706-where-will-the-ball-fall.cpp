class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int n = g[0].size();
        vector<int> t(n);
        for(int i=0;i<n;i++){
            t[i] = fun(g,0,i);
        }
        return t;
    }
    int fun(vector<vector<int>>& g,int i,int j){
        if(i==g.size()){
            return j;
        }
        if(g[i][j]==1 and (j==g[0].size()-1 or g[i][j+1]==-1)){
            return -1;
        }
        if(g[i][j]==-1 and (j==0 or g[i][j-1]==1)){
            return -1;
        }
        return fun(g,i+1,j+g[i][j]);
    }
};