class Solution {
public:
    vector<long long> maximumEvenSplit(long long f) {
        if(f%2) return {};
        long long n=1;
        long long sum = n*(n+1);
        while(sum<f){
            n++;
            sum = n*(n+1);
        }
        if(sum>f) {n--;sum=(n+1)*n;}
        vector<long long> ans(n);
        for(int i=1;i<=n;i++) ans[i-1] = 2*i;
        ans[n-1] += f-sum;
        // cout<<sum-f;
        return ans;
    }
};