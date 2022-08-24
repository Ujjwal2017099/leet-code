
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true;
        // if(n%3==0 and n/3==1) return true;
        if(n%3 != 0 ) return false;
        // if(dp[n] != -1) return dp[n];
        
        return isPowerOfThree(n/3);
    }
};