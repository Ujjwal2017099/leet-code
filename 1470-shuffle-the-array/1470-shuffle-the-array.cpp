class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        vector<int> ans;
        int x=n;
        for(int i=0;i<x;i++){
            ans.push_back(a[i]);
            ans.push_back(a[n]);n++;
        }
        return ans;
    }
};