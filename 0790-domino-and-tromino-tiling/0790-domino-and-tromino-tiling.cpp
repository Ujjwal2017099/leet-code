class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        if(n<3) return n;
        vector<long long> v(n+1);
        v[0]=1;
        v[1]=1;
        v[2]=2;
        v[3]=5;
        for(int i=4;i<=n;i++){
            v[i] = (2*v[i-1])%mod+v[i-3];
        }
        return v[n]%mod;
    }
};