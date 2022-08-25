class Solution {
public:
    vector<vector<int>> permute(vector<int>& n) {
        sort(n.begin(),n.end());
        vector<vector<int>> ans;
        do{
            ans.push_back(n);
        }while(next_permutation(n.begin(),n.end()));
        
        return ans;
    }
};