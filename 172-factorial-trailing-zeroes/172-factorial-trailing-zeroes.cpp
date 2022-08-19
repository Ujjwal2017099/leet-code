class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2=0,cnt5=0;
        for(int i=2;i<=n;i++){
            int k=i;
            while(k%2==0 and k>0){
                k/=2;
                cnt2++;
            }
            k=i;
            while(k%5==0 and k>0){
                k/=5;
                cnt5++;
            }
        }
        return min(cnt2,cnt5);
    }
};