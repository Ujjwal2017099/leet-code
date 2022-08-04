class Solution {
public:
    int mirrorReflection(int p, int q) {
        int e=q,r=p;
        while(e%2==0 and r%2==0){
            e/=2;
            r/=2;
        }
        if(e&1 and r%2==0) return 2;
        if(e%2==0 and r&1) return 0;
        
        return 1;
    }
};