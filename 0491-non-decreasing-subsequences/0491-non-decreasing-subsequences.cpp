class Solution {
public:
    vector<int> t;
    set<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& n) {
        for(int i=0;i<n.size()-1;i++){
            t.push_back(n[i]);
            fun(n,i+1,i);
            t.clear();
        }
        vector<vector<int>> ans1;
        for(auto it:ans){
            ans1.push_back(it);
        }
        return ans1;
    }
    void fun(vector<int>& v,int i,int l){
        if(i>=v.size()){
            if(t.size() >= 2){
                ans.insert(t);
            }
            return;
        }
        
        if(v[i] >= v[l]){
            t.push_back(v[i]);
            fun(v,i+1,i);
            t.pop_back();
        }
        fun(v,i+1,l);
    }
};