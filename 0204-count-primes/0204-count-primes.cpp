class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,0);
        int cnt=0;
        
        for(int i=2;i<n;i++){
            while(i<n && v[i]) i++;
            if(i==n) break;
            int j=i*2;
            cnt++;
            while(j<n){
                v[j]=1;
                j+=i;
            }
        }
        return cnt;
    }
};