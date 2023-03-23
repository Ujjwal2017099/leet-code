class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        map<int,int> m;
        fun(c,t,m);
        vector<vector<int>> x(ans.begin(),ans.end());
        return x;
    }
    void fun(vector<int>& c,int t,map<int,int>& m){
        if(t==0){
            vector<int> x;
            for(auto& it:m){
                int y=it.second;
                while(y--) x.push_back(it.first);
            }
            ans.insert(x);
            return;
        }
        
        for(int i=0;i<c.size();i++){
            if(!m[c[i]]){
                int x=t/c[i];
                
                for(int j=1;j<=x;j++){
                    m[c[i]]=j;
                    fun(c,t-j*c[i],m);
                }
                m[c[i]]=0;
            }
        }
    }
};