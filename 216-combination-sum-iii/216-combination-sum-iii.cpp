class Solution {
    public:
    vector<vector<int>> v;
    void combination(int n,int k,vector<int>& t,int val){
        if(n==0 and k==0){
            v.push_back(t);
            return;
        }
        
        if(n<=0 or k<=0){
            return;
        }
        if(val > 9) return;
        
        t.push_back(val);
        combination(n-val,k-1,t,val+1);
        t.pop_back();
        combination(n,k,t,val+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> t;
        
        combination(n,k,t,1);
        
        return v;
    }
};