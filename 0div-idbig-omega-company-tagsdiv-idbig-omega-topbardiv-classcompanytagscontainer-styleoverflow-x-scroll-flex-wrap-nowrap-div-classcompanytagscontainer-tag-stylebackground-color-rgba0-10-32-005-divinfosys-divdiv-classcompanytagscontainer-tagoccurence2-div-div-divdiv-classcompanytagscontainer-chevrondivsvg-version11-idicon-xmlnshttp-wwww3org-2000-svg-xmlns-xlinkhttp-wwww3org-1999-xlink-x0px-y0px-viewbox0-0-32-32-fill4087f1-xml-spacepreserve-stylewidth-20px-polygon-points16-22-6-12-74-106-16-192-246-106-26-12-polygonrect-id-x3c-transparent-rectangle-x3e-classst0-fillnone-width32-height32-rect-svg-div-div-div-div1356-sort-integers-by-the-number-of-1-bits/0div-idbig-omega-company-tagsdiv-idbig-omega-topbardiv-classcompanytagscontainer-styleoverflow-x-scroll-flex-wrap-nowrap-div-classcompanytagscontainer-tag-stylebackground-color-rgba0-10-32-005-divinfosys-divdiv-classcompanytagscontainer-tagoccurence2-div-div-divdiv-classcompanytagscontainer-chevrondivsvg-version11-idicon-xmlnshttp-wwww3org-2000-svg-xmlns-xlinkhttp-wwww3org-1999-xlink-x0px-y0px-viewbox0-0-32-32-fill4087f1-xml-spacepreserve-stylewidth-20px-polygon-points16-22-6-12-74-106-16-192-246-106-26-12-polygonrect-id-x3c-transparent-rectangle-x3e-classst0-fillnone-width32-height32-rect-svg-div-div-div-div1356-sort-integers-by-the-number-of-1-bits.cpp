class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(),a.end(),[&](int x,int y){
            int c1=__builtin_popcount(x),c2=__builtin_popcount(y);
            if(c1==c2) return x<y;
            return c1<c2;
        });
        return a;
    }
};