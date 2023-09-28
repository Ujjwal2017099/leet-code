class Solution {
public:
    bool canMeasureWater(int a, int b, int t) {
        return t%__gcd(a,b)==0  && t<=a+b;
    }
};