class Solution {
public:
    int countPrimes(int n) {
        bool arr[n+1];
        memset(arr,1,sizeof(arr));
        
        for(int i=2;i<=n/2;i++){
            int j=2;
            if(!arr[i]){
                continue;
            }
            while(i*j<=n){
                arr[i*j] = 0;
                j++;
            }
        }
        
        int cnt = 0;
        
        for(int i=2;i<n;i++){
            if(arr[i]) cnt++;
        }
        
        return cnt;
    }
};