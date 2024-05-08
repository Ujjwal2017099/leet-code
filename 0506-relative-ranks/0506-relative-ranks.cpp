class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
        vector<int> v(s.begin(),s.end());
        map<int,int> mp;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) mp[v[i]]=v.size()-i;
        
        vector<string> ans(s.size());
        
        for(int i=0;i<s.size();i++){
            int x = mp[s[i]];
            
            if(x==1) ans[i]="Gold Medal";
            else if(x==2) ans[i]="Silver Medal";
            else if(x==3) ans[i]="Bronze Medal";
            else ans[i]=to_string(x);
        }
        return ans;
    }
};