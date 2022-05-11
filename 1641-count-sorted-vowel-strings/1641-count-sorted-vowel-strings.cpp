class Solution {
int dp[100][100] = {{0}};
    public:
    // vector<char> ss;
    int solve(int n,int i){
        
        if(n==0) return 1;
        // if(i>=5) return 0;
        int res=0;
        for(int j=i;j<5;j++){
            if(dp[n-1][j]) {res+= dp[n-1][j];}
            else{
                res+=solve(n-1,j);
                // dp[n-1][j] = res;
            }
        }
        return res;
    }
    int countVowelStrings(int n) {
        // ss = {'a','e','i','o','u'};
        return solve(n,0);
    }
};