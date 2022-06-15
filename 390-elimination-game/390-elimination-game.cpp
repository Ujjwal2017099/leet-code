class Solution {
public:
    int f(int n) {
        if (n <= 2) return n - 1;
        if (n % 2 == 1) return n - 2 - 2 * f(n/2);
        else return n - 1 - 2 * f(n/2);
    }
    int lastRemaining(int n) {
        return f(n) + 1;
    }
};