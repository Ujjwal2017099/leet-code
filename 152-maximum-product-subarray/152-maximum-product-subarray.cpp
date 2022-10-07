class Solution {
public:
    int maxProduct(vector<int>& n) {
        int ans = n[0];
        int mx = n[0];
        int mn = n[0];
        
        for(int i=1;i<n.size();i++){
            if(n[i]<0) swap(mx,mn);
            mx = max(n[i],n[i]*mx);
            mn = min(n[i],n[i]*mn);
            ans = max(ans,max(mx,mn));
            
        }
        ans = max(ans,max(mx,mn));
        return ans;
    }
};