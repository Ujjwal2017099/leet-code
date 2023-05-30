class NumMatrix {
public:
    vector<vector<int>> t;
    NumMatrix(vector<vector<int>>& m) {
        t.resize(m.size()+2,vector<int>(m[0].size()+2,0));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                t[i+1][j+1] = m[i][j]+t[i][j+1]+t[i+1][j]-t[i][j];
                // cout<<t[i+1][j+1]<<" ";
            }
            // cout<<endl;
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        // cout<<t[r1][c2+1]<<endl;
        return t[r2+1][c2+1]-t[r1][c2+1]-t[r2+1][c1]+t[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */