class Solution {
public:
    vector<int> sortedSquares(vector<int>& n) {
        vector<int> ans;
        int l=0,r=n.size()-1;
        while(l<r){
            if(n[l]*n[l] < n[r]*n[r]){
                ans.push_back(n[r]*n[r]);
                r--;
            }else{
                ans.push_back(n[l]*n[l]);
                l++;
            }
        }
        ans.push_back(n[l]*n[l]);
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};