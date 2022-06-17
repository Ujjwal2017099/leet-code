class Solution {
public:
    void fun(vector<int>& v,int k,int a){
        if(v.size() == 1) return;
        
        while(k >= v.size()) k-=v.size();
        
        v.erase(v.begin()+k);
        fun(v,k+a,a);
    }
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        k--;
        int a=k;
        // while(v.size()!=1){
        //     while(k>=v.size()){
        //         k-=v.size();
        //     }
        //     v.erase(v.begin()+k);
        //     k+=a;
        // }
        
        fun(v,k,a);
        return v[0];
    }
};