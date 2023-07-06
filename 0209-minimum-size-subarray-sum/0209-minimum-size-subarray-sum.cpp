class Solution {
public:
    int minSubArrayLen(int x, vector<int>& n) {
        vector<int> t(n.size()+1);t[0]=0;
        partial_sum(n.begin(),n.end(),t.begin()+1);
        int l=0,r=1;
        int ans=INT_MAX;
        while(r<t.size()){
            if(t[r]-t[l]>=x){
                ans=min(ans,r-l);
                l++;
            }else{
                r++;
            }
        }
        while(l<r){
            if(t.back()-t[l]<x) break;
            ans=min(ans,(int)t.size()-l);
            l++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};