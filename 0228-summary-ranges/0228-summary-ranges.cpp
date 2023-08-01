class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        if(n.empty()) return {};
        vector<string> ans;
        int p=n[0];
        int curr=n[0];
        for(int i=1;i<n.size();i++){
            if(n[i]==curr+1){
                curr=n[i];
            }else{
                if(curr==p) ans.push_back(to_string(p));
                else ans.push_back(to_string(p) + "->" + to_string(curr));
                p=curr=n[i];
            }
        }
        if(curr==p) ans.push_back(to_string(p));
        else ans.push_back(to_string(p) + "->" + to_string(curr));
        return ans;
    }
};