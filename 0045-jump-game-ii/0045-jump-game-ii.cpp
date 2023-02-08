class Solution {
public:
    int jump(vector<int>& n) {
        int ans=0;
        int mx =0,end=0;
        for(int i=0;i<n.size()-1;i++){
            mx = max(mx,n[i]+i);
            
            if(i==end){
                end = mx;
                ans++;
            }
        }
        return ans;
    }
};