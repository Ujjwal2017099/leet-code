class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n) {
        int ans=INT_MAX;
        int l=0;
        partial_sum(n.begin(),n.end(),n.begin());
        if(n.back()>=target) ans=n.size();
        for(int i=0;i<n.size();i++){
            while(l<i && n[i]-n[l]>=target){
                ans=min(ans,i-l);
                l++;
                // cout<<i-l+1<<" ";
            }
            if(n[i]>=target){
                ans=min(ans,i+1);
            }
        }
        while(l<n.size() && n.back()-n[l]>=target){
            int i=n.size();
            ans=min(ans,i-l);l++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};