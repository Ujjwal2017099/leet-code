class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
         fun(nums,0,t);
        
        return ans;
    }
     void fun(vector<int> n,int i,vector<int> t){
        if(i==n.size()){
            ans.push_back(t);
            return;
        }
        
        // ans.push_back(t);
        t.push_back(n[i]);
        fun(n,i+1,t);
        t.pop_back();
        fun(n,i+1,t);
    }
};