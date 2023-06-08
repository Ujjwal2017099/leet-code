class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int cnt=0;
        int rl=g.size()-1,cl=g[0].size()-1;
        for(int i=0;i<=rl;i++){
            for(int j=0;j<=cl;j++){
                if(g[i][j]<0){
                    cnt += (rl - i +1)*(cl -j +1);
                    cl = j-1;
                }
            }
        }
        return cnt;
    }
};