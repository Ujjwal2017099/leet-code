class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<int> x(n,0),y(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    x[i]++;
                    y[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(x[i]==1 && y[j]==1 && v[i][j]) ans++;
            }
        }
        return ans;
    }
};