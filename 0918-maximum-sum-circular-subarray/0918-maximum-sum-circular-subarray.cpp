class Solution {
public:
    int maxSubarraySumCircular(vector<int>& n) {
        if(n.size()==1) return n[0];
        int sm=n[0];
        int ans=INT_MIN;
        vector<int> pref(n.size(),ans),suff(n.size(),ans);
        pref[0] = n[0];
        for(int i=1;i<n.size();i++){
            // if(sm<0){
            //     sm=0;
            // }
            sm += n[i];
            pref[i] = max(pref[i-1],sm);
        }
        sm =n.back();
        suff[n.size()-1] = n.back();
        for(int i=n.size()-2;i>=0;i--){
            // if(sm<0){
            //     sm=0;
            // }
            sm += n[i];
            suff[i] = max(suff[i+1],sm);
        }
        for(int i=0;i<n.size()-2;i++){
            ans = max(ans,pref[i]+suff[i+1]);
        }
        ans = max(ans,pref.back());
        sm = 0;
        for(int i=0;i<n.size();i++){
            if(sm<0){
                sm=0;
            }
            sm += n[i];
            ans = max(ans,sm);
        }
        return ans;
    }
};