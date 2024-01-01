class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int ans=0;
        auto prev = s.begin();
        for(int i=0;i<g.size();i++){
            auto it=lower_bound(prev,s.end(),g[i]);
            if(it==s.end()) break;
            
            ans++;
            prev=next(it,1);
        }
        return ans;
    }
};