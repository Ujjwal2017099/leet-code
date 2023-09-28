class Solution {
public:
    bool canMeasureWater(int a, int b, int t) {
        
        return (t%__gcd(a,b)==0 || t==a || t==b || t==a+b) && t<=a+b;
    }
};