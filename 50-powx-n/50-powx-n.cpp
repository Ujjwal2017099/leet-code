class Solution {
    double temp;
    double power(double x,int n){
        if(n == 0) return 1;
        temp = power(x,n/2);
        if(n%2)
            return x*temp*temp;
        else
            return temp*temp;
    }
public:
    double myPow(double x, int n) {
        if(n < 0) x = 1/x;
        temp = 0;
        return power(x,n);
    }
};