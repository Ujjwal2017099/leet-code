class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<int> m;
        map<int,int> mp;
        for(int i:c){
            if(i>t || mp[i]*i>t) continue;
            mp[i]++;
        }
        vector<int> y;
        for(auto& it:mp) {
            int a=it.second;
            while(a--) y.push_back(it.first);
        }
        fun(y,t,m,0);
        vector<vector<int>> x(ans.begin(),ans.end());
        return x;
    }
    void fun(vector<int>& c,int t,vector<int>& m,int k){
        if(t==0){
            ans.insert(m);
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