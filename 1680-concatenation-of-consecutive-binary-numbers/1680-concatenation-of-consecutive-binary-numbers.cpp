class Solution {
public:
    long long mod=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        long long prev = 0;
        for(long long i=1;i<=n;i++){
            if(i!=1) prev = log2(i)+1;
            ans = ((ans<<prev)%mod + i%mod)%mod;
        }
        
        return ans;
    }
};