class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        n--;
        for(int i=1;i<=9;i++) {
            fun(n,k,i,i+k);
            if(n!=0 and i-k != i+k) fun(n,k,i,i-k);
        }
        // vector<int> t;
        // for(auto i:ans){
        //     t.push_back(i);
        // }
        return ans;
    }
    void fun(int n,int k,int num,int a){
        if(n==0){
            ans.push_back(num);
            return ;
        }
        if(a>9 || a<0) return;
        
        num = num*10 + a;
        n--;
        fun(n,k,num,a+k);
        if(n!=0 and a-k!=a+k)fun(n,k,num,a-k);
    }
};