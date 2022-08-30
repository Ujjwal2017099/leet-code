class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size()-1;
        int s = (n+1)/2;
        for(int i=0;i<s;i++){
            for(int j=i;j<n-i;j++){
                int t = m[i][j];
                int x = i,y = j;
                for(int k=1;k<=4;k++){
                    int z = m[y][n-x];
                    x = n-x;
                    m[y][x] = t;
                    t= z;swap(y,x);
                }
            }
        }
    }
};