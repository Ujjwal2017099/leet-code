class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> m;
        fun(c,t,m,0);
        return ans;
    }
    void fun(vector<int>& c,int t,vector<int>& m,int k){
        if(t==0){
            ans.push_back(m);
            return;
        }
        
        for(int i=k;i<c.size();i++){
            
            int x=t/c[i];
            
            for(int j=1;j<=x;j++){
                m.push_back(c[i]);
                fun(c,t-j*c[i],m,i+1);
            }
            while(x--) m.pop_back();
            
        }
    }
};