const int N=5e4+5;
class Solution {
public:
    int calc(vector<vector<int> >&dp, vector <int>&val, int i, int pick) {
        if (i>=val.size()) {
            if (pick==2) return 0;
            else return INT_MIN;     
        } 
        if (dp[i][pick]!=-1) return dp[i][pick];
        dp[i][pick]=0;
        if (pick == 0) dp[i][pick]=max(calc(dp, val, i+1, pick+1)+i+val[i], calc(dp, val, i+1, pick));
        else if (pick == 1) dp[i][pick]= max(calc(dp, val, i+1, pick+1)-i+val[i], calc(dp, val, i+1, pick));
        return dp[i][pick];
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        vector <vector<int> >dp(values.size()+2, vector<int> (3, -1));
        return calc(dp, values, 0, 0);
	}
};