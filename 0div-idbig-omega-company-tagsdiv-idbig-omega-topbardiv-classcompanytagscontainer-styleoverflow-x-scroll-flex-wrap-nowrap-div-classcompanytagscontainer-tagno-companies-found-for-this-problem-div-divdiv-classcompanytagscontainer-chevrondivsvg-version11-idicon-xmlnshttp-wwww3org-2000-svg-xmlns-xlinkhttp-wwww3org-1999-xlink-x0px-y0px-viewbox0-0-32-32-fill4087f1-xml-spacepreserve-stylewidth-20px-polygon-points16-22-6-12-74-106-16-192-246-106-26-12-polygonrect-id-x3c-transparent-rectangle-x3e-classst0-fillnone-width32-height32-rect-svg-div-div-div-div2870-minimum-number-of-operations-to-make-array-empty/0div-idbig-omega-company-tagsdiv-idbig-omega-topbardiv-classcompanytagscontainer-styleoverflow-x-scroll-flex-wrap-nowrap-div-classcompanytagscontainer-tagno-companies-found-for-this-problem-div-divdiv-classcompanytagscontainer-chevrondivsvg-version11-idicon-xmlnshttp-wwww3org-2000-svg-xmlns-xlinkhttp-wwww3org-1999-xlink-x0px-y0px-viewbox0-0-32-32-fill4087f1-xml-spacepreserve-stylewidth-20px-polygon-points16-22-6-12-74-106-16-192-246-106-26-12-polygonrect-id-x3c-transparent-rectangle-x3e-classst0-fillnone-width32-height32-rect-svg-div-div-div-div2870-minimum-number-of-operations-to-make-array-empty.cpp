class Solution {
public:
    int minOperations(vector<int>& n) {
        map<int,int> mp;
        for(int i:n) mp[i]++;
        int ans=0;
        for(auto it:mp){
            if(it.second==1) return -1;
            int x=(it.second/3) + (it.second%3 ? 1 : 0),y=it.second/2 + (it.second%2 ? 1 : 0);
            ans+=min(x,y);
        }
        return ans;
    }
};