class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        if(nums.size()==1 and k==nums[0]) return 1;
        for (int i = 0; i < nums.size(); i++){
            unsigned long long p = nums[i];
            for(int j=i+1;j<nums.size();j++){
                long long x = nums[j];
                long long y = gcd(nums[j],p); 
                
                p/=y;
                p*=x;
                
                if(p==k) {
                    cnt++;
                    
                    // cout<<i<<" "<<j<<endl;
                }
                
                
            }
        }
        for(int i:nums) if(i==k) cnt++;
        return cnt;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};