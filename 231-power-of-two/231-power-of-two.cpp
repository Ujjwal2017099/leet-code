class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        if(n & 1 or n < 1) return false;
        
        return isPowerOfTwo(n/2);
    }
};