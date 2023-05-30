class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n) {
        int ans=INT_MAX;
        int l=0,sm=0;
        for(int i=0;i<n.size();i++){
            sm+=n[i];
            while(l<=i && sm>=target){
                ans=min(ans,i-l+1);
                sm-=n[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};