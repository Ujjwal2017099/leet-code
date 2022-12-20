class Solution {
public:
    int smallestValue(int n) {
        vector<int> v(n+1,1);
        for(int i=2;i<=sqrt(n);i++){
            if(v[i]==1){
                int j=i*2;
                while(j<=n){
                    v[j]=0;
                    j+=i;
                }
            }
        }
        
        int ans=n;
        while(!v[ans]){
            map<int,bool> mp;
            int x = fun(ans,v,mp);
            // cout<<x<<endl;
            if(x==ans) return ans;
            ans=x;
        }
        return ans;
    }
    int fun(int n,vector<int>& v,map<int,bool>& mp){
        if(v[n]){mp[n]=1; return n;}
        int sum=0;
        for(int i=2;i<=sqrt(n);i++){
            if(!mp[i] && v[i] && n%i==0){
                // mp[i] = 1;
                sum += fun(n/i,v,mp)+i;
                // cout<<i<<" ";
                mp[i]=1;
            }
        }
        return sum;
    }
};