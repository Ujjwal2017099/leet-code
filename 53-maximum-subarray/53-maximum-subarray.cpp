class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int sum = 0;
        int ans=INT_MIN;
        for(int i=0;i<n.size();i++){
            if(sum<0) sum=0;
            sum+=n[i];
            ans = max(sum,ans);
        }
        return ans;
    }
};