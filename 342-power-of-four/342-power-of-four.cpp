class Solution {
public:
    bool isPowerOfFour(int n) {
        // return n<=0? 0 : n==1? 1 : n%4!=0 ? 0 : isPowerOfFour(n/4);
        return n > 0 && __builtin_popcountll(n) == 1 && (n - 1) % 3 == 0;
    }
};