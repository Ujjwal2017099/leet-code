class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;

    vector<vector<int>> combine(int n, int k) {
        fun(1,n,k,0);
        return ans;
    }
    void fun(int i,int n,int k,int x){
        if(i>n || k==x) return;
        fun(i+1,n,k,x);
        t.push_back(i);
        fun(i+1,n,k,x+1);
        if(t.size()==k){
            ans.push_back(t);
        }
        t.pop_back();
    }
};