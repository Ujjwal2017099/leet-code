class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> cnt(100001,0);
        for(int i:arr){
            cnt[i]++;
        }
        sort(cnt.begin(),cnt.end(),[&](int a,int b){
           return a>b; 
        });
        
        int i=0;
        int ans=0,sum=0;
        while(i<=100000 and sum<arr.size()/2){
            sum+=cnt[i];i++;
            ans++;
        }
        return ans;
    }
};