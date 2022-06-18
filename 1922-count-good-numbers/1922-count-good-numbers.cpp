class Solution {
    const int mod = 1e9+7;
public:
    long long  power(long long a,long long b){
        a = a%mod;
        // b = b%mod;
        if(b==0) return 1;
        if(b==1) return a;
        
        long long t = power(a,b/2);
        if(b%2==0){
            return ((t%mod)*(t%mod))%mod;
        }else{
            return ((t%mod)*(t%mod)*(a%mod))%mod;
        }
    }
    int countGoodNumbers(long long n) {
        
        if(n%2==0){
            return ((power(5,n/2)%mod)*(power(4,n/2)%mod))%mod;
        }else return ((power(5,n/2 + 1)%mod)*(power(4,n/2)%mod))%mod;
    }
};