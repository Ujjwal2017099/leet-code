class Solution {
public:
    int poorPigs(int b, int m2die, int m2test) {
        int k = (m2test/m2die) + 1;
        
        return ceil(log(b)/log(k));
    }
};