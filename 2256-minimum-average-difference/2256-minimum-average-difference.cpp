class Solution {
public:
    int minimumAverageDifference(vector<int>& n) {
        vector<long long> t(n.size()+2);
        t[0] = 0;
        for(int i=1;i<=n.size();i++){
            t[i] = t[i-1] + n[i-1];
        }
        t[n.size()+1] = t[n.size()];
        long long mn = INT_MAX;
        int ans = 0;
        for(int i=1;i<=n.size();i++){
            long long a = (t[i])/i;
            long long b = (t[n.size()] - t[i]);
            if(b) b/=(n.size()-i);
            long long dif = abs( a - b); 
            if(dif < mn){
                mn = dif;
                ans= i-1;
            }
        }
        return ans;
    }
};