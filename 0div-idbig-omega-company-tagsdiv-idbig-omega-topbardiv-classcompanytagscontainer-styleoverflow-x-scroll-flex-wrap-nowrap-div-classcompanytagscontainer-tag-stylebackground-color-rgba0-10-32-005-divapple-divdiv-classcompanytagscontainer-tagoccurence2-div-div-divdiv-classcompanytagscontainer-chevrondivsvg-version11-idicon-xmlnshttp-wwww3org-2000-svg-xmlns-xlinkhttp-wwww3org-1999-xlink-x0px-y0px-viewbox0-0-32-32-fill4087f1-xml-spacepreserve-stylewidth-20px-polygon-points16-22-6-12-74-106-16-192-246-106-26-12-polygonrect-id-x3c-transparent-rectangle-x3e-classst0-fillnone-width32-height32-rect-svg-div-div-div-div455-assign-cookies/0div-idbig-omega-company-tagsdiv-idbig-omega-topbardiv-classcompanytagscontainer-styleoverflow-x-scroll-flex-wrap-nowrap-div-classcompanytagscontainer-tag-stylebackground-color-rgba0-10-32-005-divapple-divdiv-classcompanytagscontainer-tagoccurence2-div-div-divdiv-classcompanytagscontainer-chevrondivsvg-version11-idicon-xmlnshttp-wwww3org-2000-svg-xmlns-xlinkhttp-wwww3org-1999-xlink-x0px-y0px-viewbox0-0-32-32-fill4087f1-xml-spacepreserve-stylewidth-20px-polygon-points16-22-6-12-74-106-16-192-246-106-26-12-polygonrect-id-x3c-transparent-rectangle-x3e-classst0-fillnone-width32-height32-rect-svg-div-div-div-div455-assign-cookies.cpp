class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int ans=0;
        auto x = s.begin();
        for(int i:g){
            auto it = lower_bound(x,s.end(),i);
            if(it==s.end()) break;
            ans++;
            // cout<<*it;
            x=it+1;
        }
        return ans;
    }
};