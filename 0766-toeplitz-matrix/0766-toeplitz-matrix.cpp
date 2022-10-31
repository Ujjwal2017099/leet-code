class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        for(int j=0;j<c;j++){
            for(int i=0;i<r;i++){
                if(i>0 and j>0 and m[i-1][j-1]!=m[i][j]){
                    return 0;
                }
            }
        }
        return 1;
    }
};