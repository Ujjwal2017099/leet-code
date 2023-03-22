class Solution {
public:
    long long repairCars(vector<int>& r, long long c) {
        sort(r.begin(),r.end());
        long long a=r[0];
        long long ans = a*c*c;
        
        long long l=1;
        
        while(l<ans){
            long long md = l+(ans-l)/2;
            if(check(md,r,c)) ans=md;
            else l=md+1;
        }
        return ans;
    }
    bool check(long long t,vector<int>& r,int c){
        int n=r.size();
        // vector<int> cnt(n,0);
        for(int i=0;i<n;i++){
            if(c<=0) return 1;
            int x = sqrt(t/r[i]);
            c-=x;
        }
        return c<=0? 1:0;
    }
};