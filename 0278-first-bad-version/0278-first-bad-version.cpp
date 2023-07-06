// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(long long n) {
        long long f=0;
        int prev = n;
        while(f<n){
            int md=(n+f)/2;
            if(md==prev) break;
            if(isBadVersion(md)){
                n=md;
            }else{
                f=md;
            }
            prev=md;
        }
        return n;
    }
};