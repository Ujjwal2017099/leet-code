class Solution {
public:
    int numIdenticalPairs(vector<int>& n) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n.size();i++){
            if(mp[n[i]]){
                ans+=mp[n[i]];
            }
            mp[n[i]]++;
        }
        return ans;
    }
};