class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> v(n,vector<int>(n,0));
        for(vector<int> t:q){
            int ux=t[0],uy=t[1];
            int vx=t[2],vy=t[3];
            for(int i=ux;i<=vx;i++){
                v[i][uy]++;
                if(vy+1<n) v[i][vy+1]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                v[i][j]+=v[i][j-1];
            }
        }
        return v;
    }
};