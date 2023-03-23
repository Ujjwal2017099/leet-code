class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> m;
        fun(c,t,m,0);
        // vector<vector<int>> x(ans.begin(),ans.end());
        return ans;
    }
    void fun(vector<int>& c,int t,vector<int>& m,int k){
        // if(k==c.size()) return;
        if(t==0){
            // vector<int> x;
            // for(auto& it:m){
            //     int y=it.second;
            //     while(y--) x.push_back(it.first);
            // }
            ans.push_back(m);
            return;
        }
        
        for(int i=k;i<c.size();i++){
            // if(!m[c[i]]){
                int x=t/c[i];
                
                for(int j=1;j<=x;j++){
                    m.push_back(c[i]);
                    fun(c,t-j*c[i],m,i+1);
                }
                while(x--) m.pop_back();
            // }
        }
    }
};