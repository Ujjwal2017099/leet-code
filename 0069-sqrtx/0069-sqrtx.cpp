class Solution {
public:
    int mySqrt(int x) {
        long long l=x;
        long long c=x;
        while(c*c > x){
            l=c;
            c>>=1;
        }
        long long prev=l;
        while(c<l){
            long long md = (l+c)/2;
            if(md==prev) break;
            if(md*md==x) return md;
            if(md*md > x){
                l=md-1;
            }else{
                c = md;    
            }
            prev=md;
        }
        while((c+1)*(c+1)<=x) c++;
        return c;
    }
};