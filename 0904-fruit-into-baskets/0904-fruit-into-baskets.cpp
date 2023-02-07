class Solution {
public:
    int totalFruit(vector<int>& f) {
        set<int> s;
        map<int,int> mp;
        int cnt=0;
        int ans=0;
        int i=0;
        int prev=0;
        for(i=0;i<f.size();i++){
            if(mp[f[i]]==0 && s.size()==2){
                if(mp[f[prev]]==1) s.erase(f[prev]);
                mp[f[prev]]--;
                cnt--;i--;
                prev++;
            }
            else{
                mp[f[i]]++;
                s.insert(f[i]);
                cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};