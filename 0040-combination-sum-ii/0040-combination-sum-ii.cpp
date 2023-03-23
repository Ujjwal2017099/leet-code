class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<int> m;
        sort(c.begin(),c.end());
        fun(c,t,m,0);
        // vector<vector<int>> x(ans.begin(),ans.end());
        return ans;
    }
    void fun(vector<int>& c,int t,vector<int>& m,int k){
        if(t==0){
            ans.push_back(m);
            return;
        }
        if(t<0) return;
        for(int i=k;i<c.size();i++){
            if(i>k && c[i]==c[i-1]) continue;
            m.push_back(c[i]);
            fun(c,t-c[i],m,i+1);

            m.pop_back();
            
        }
    }
};