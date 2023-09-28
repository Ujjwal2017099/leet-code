class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& n) {
        vector<int> ans(n.size());
        int e=0,o=n.size()-1;
        for(int i=0;i<n.size();i++){
            if(n[i]&1){
                ans[o]=n[i];o--;
            }else{
                ans[e]=n[i];e++;
            }
        }
        return ans;
    }
};