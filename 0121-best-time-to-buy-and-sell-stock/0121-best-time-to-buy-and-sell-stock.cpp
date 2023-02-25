class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        vector<int> mn(p.size());
        vector<int> mx(p.size());
        mn[0]=p[0];
        mx.back()=p.back();
        for(int i=1;i<p.size();i++)
            mn[i]=min(mn[i-1],p[i]);
        for(int i=p.size()-2;i>=0;i--)
            mx[i]=max(mn[i+1],p[i]);
        for(int i=0;i<p.size();i++){
            ans=max(ans,mx[i]-mn[i]);
        }
        return ans;
    }
};