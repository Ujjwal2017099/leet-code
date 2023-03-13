class Solution {
public:
    long long beautifulSubarrays(vector<int>& n) {
        vector<int> t(n.size());
        t[0]=n[0];
        for(int i=1;i<n.size();i++){
            t[i] = t[i-1] ^ n[i];
        }
        unordered_map<int,long long> mp;
        long long ans=0;
        for(int i=0;i<n.size();i++){
            ans += mp[t[i]]++;
            if(t[i]==0) ans++;
        }
        
        return ans;
    }
};