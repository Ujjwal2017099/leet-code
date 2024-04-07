class Solution {
public:
    int longestMonotonicSubarray(vector<int>& n) {
        int ans=1;
        int len=1;
        for(int i=1;i<n.size();i++){
            if(n[i]>n[i-1]){
                len++;
            }else{
                len=1;
            }
            ans = max(ans,len);
        }
        len=1;
        for(int i=1;i<n.size();i++){
            if(n[i]<n[i-1]){
                len++;
            }else{
                len=1;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};