class Solution {
public:
    int singleNumber(vector<int>& n) {
        int ans=n[0];
        for(int i=1;i<n.size();i++){
            ans^=n[i];
        }
        return ans;
    }
};