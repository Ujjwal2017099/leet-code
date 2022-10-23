class Solution {
public:
    vector<int> findErrorNums(vector<int>& n) {
        vector<int> ans;
        vector<int> t(n.size()+1,0);
        for(int i:n){
            if(t[i]){
                ans.push_back(i);
            }
            t[i]++;
        }
        for(int i=1;i<=n.size();i++){
            if(t[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};