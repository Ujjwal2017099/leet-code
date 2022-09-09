class Solution {
public:
    int i;
    vector<int> p;
    bool isStrictlyPalindromic(int n) {
        for(int j=2;j<=n-2;j++){
            i = j;
            // p.push_back(n%j);
            fun(n/j,n%j);
            for(int i:p){
                cout<<i<<" ";
            }
            cout<<endl;
            bool ok = equal(p.begin(), p.begin() + p.size()/2  , p.rbegin());
            if(!ok) return 0;
            p.clear();
        }
        return 1;
    }
    void fun(int n,int r){
        if(n==0){
            p.push_back(r);
            return;
        }
        fun(n/i,n%i);
        p.push_back(r);
    }
};