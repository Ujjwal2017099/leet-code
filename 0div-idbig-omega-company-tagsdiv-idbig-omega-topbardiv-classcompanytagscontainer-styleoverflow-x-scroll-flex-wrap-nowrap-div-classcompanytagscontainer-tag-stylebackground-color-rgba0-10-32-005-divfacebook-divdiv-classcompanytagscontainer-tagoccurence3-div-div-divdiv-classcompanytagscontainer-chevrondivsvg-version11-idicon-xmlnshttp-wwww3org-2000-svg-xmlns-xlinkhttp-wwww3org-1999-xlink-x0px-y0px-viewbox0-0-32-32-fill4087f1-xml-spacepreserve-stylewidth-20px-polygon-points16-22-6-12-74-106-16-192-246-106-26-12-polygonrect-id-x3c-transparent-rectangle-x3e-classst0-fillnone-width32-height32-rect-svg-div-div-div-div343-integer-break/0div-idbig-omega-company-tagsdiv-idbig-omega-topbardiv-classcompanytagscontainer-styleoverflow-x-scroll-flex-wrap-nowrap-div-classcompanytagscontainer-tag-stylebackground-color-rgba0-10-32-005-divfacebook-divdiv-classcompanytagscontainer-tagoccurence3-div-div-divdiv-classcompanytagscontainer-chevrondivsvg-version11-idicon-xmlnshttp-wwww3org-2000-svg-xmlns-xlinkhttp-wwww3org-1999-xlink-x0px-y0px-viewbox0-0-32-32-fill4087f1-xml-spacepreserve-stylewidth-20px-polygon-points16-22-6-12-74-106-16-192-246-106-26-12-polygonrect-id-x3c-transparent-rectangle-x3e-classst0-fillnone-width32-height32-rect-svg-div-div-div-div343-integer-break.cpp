class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        vector<int> d(n+1);
        d[1]=1;
        d[2]=1;
        d[3]=2;
        if(n<=3) return d[n];
        int ans=1;
        for(int i=4;i<=n;i++){
            for(int j=1;j<i;j++){
                d[i] = max(d[i],max(j,d[j])*max(i-j,d[i-j]));
            }
        }
        // for(int i=2;i<=n;i++) cout<<d[i]<<" ";
        return d[n];
    }
};