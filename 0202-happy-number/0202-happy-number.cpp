class Solution {
public:
    bool isHappy(int n) {
        map<int,bool> m;
        while(n){
            if(n==1) return 1;
            if(m[n]) return 0;
            int sum=0;
            m[n]=1;
            while(n){
                sum+=(n%10)*(n%10);
                n/=10;
            }
            n=sum;
        }
        return 0;
    }
};