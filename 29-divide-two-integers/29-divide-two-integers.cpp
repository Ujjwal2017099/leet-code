class Solution {
public:
    int divide(int dividend, int divisor) {
        long long div = dividend,d=divisor;
        long long x = div/d;
        if(x>INT_MAX) return INT_MAX;
        else if(x<INT_MIN) return INT_MIN;
        return x;
    }
};