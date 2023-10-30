class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(),a.end(),[&](int x,int y){
            int c1=0,c2=0;
            int u=x,v=y;
            while(x){
                c1++;
                x=(x&(x-1));
            }
            while(y){
                c2++;
                y=(y&(y-1));
            }
            if(c1==c2) return u<v;
            return c1<c2;
        });
        return a;
    }
};