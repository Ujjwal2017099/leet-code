class Solution {
public:
    vector<vector<int>> d = {{0,1},{1,0}};
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        
        return fun(n,k,0);
    }
    int fun(int n , int k,int curr){
        if(n==1) return curr;
        
        int x = (1<<(n-1));
        if(x/2 >= k){
            return fun(n-1,k,d[curr][0]);
        }
        
        return fun(n-1,k-x/2,d[curr][1]);
    }
};