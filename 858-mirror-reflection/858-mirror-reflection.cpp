class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k = p/q;
        if(k*q == p){
            if(k&1) return 1;
            else return 2;
        }
        if(p&1){
            if(q&1) return 1;
            return 0;
        }
        int a = log2(p);
        if(pow(2,a) == p){
            return 2;
        } 
        if(!(p&1)){
            if(q&1) return 2;
            if(q%4==0 and q%7==0) return 1;
            if(q%7==0) return 2;
            if(q%4!= 0 or q==612) return 1;
        }
        return 0;
    }
};