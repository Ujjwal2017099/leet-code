class Solution {
public:
    int majorityElement(vector<int>& n) {
        int ans=0;
        int cnt=0;
        for(int i:n){
            if(!cnt){
                ans=i;
            }
            cnt += (i==ans) ? 1:-1;
        }
        return ans;
    }
};