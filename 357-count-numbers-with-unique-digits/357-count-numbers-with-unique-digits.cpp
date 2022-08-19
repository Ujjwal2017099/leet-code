class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        for(int i=0;i<n;i++) ans += 9*fun(i,9);
        
        return ans;
    }
    int fun(int n,int cnt){
        if(n==0) return 1;
        
        return fun(n-1,cnt-1)*cnt;
    }
};