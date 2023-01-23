class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<int> v(n+1,0);
        vector<int> x(n+1,0);
        for(auto it:t){
            v[it[1]]++;
            x[it[0]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(x[i]==0 && v[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};