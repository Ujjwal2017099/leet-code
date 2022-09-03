class Solution {
public:
    set<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++) {
            fun(n-1,k,i,i+k);
            fun(n-1,k,i,i-k);
        }
        vector<int> t;
        for(auto i:ans){
            t.push_back(i);
        }
        return t;
    }
    void fun(int n,int k,int num,int a){
        if(n==0){
            if(a>=0 and a<=9){
                // num = num*10 + a;
                ans.insert(num);
            }
            return ;
        }
        if(a>9 || a<0) return;
        
        num = num*10 + a;
        fun(n-1,k,num,num%10+k);
        fun(n-1,k,num,num%10-k);
    }
};