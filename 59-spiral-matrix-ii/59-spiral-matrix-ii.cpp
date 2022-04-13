class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int one = 0 , two = n-1; 
        
        vector<vector<int>> v(n,vector<int>(n));
        
        int val = 1;
        int left = -1 , up = 0;
        while(val <= n*n)
        {
            int r1 = one , r2 = two;
            int c1 = one , c2 = two;
            left++,up++;
            while(c1<=c2 and val <= n*n) {v[r1][c1] = val , val++, c1++ ;} c1-- , r1++;
            while(r1<=r2 and val <= n*n) {v[r1][c1] = val, val++ , r1++  ;} r1-- , c1--;
            while(c1 >=left and val <= n*n) {v[r1][c1] = val, val++ , c1-- ; }c1++ , r1--;
            while(r1 >= up and val <= n*n){ v[r1][c1] = val, val++ , r1-- ;}  r1++ ;
            one++ , two--;
        }
        return v;
    }
};