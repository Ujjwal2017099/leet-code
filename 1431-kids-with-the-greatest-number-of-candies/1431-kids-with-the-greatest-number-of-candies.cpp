class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ex) {
        vector<bool> ans(c.size(),0);
        int mx=0;
        for(int i=0;i<c.size();i++){
            mx=max(mx,c[i]);
        }
        for(int i=0;i<c.size();i++){
            if(c[i]+ex>=mx) ans[i]=1;
        }
        return ans;
    }
};