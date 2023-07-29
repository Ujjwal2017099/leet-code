class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<vector<int>> t;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    t.push_back({i,j});
                }
            }
        }
        for(vector<int>& x:t){
            int u=x[0],v=x[1];
            for(int j=0;j<m[0].size();j++) m[u][j]=0;
            for(int i=0;i<m.size();i++) m[i][v]=0;
        }
    }
};