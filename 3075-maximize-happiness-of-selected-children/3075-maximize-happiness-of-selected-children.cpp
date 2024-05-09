class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end(),greater<int>());
        int s=0;
        long long ans=0;
        
        for(int i=0;i<k;i++){
            long long x = (h[i]-s>=0 ? (h[i]-s) : 0);
            ans += x;
            s++;
        }
        return ans;
    }
};