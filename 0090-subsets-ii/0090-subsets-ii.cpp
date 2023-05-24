class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> t;
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        fun(nums,n,t);
        vector<vector<int>> x(ans.begin(),ans.end());
        return x;
    }
    void fun(vector<int>& a,int n,vector<int>& s){
        if(n<0) {
            ans.insert(s);
            return ;
        }
        
        fun(a,n-1,s);
        s.push_back(a[n]);
        fun(a,n-1,s);
        s.pop_back();
    }
};