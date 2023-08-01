class Solution {
public:
    vector<int> majorityElement(vector<int>& n) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<n.size();i++){
            m[n[i]]++;
        }
        for(auto& it:m){
            if(it.second>n.size()/3) ans.push_back(it.first);
        }
        return ans;
    }
};