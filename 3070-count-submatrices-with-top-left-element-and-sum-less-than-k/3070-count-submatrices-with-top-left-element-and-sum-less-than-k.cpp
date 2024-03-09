class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        for(int i=0;i<g.size();i++){
            for(int j=1;j<g[0].size();j++){
                g[i][j]+=g[i][j-1];
            }
        }
        
        for(int i=1;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                g[i][j]+=g[i-1][j];
            }
        }
        int ans=0;
        
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};