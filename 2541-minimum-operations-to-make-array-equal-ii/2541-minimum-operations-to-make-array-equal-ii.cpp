class Solution {
public:
    long long minOperations(vector<int>& n1, vector<int>& n2, int k) {
        int n=n1.size();
        vector<int> t(n);
        long long ans=0;
        for(int i=0;i<n;i++){
            t[i] = n2[i]-n1[i];
            if(k==0 && t[i]!=0) return -1;
            // cout<<t[i]<<" ";
        }
        if(k==0) return 0;
        sort(t.begin(),t.end());
        int l=0,r=n-1;
        
        
        while(l<r){
            while(l<n && t[l]==0) l++;
            while(r>=0 && t[r]==0) r--;
            if(r<0 || l>n-1) break;
            if(t[l]>0 || t[r]<0) return -1;
            int x=-1*t[l],y=t[r];
            if(x%k!=0 || y%k!=0) return -1;
            ans += min(x/k,y/k);
            t[l] += min(x/k,y/k)*k; if(t[l]==0) l++;
            t[r] -= min(x/k,y/k)*k; if(t[r]==0) r--;
        }
        for(int i:t){
            if(i!=0) return -1;
        }
        return ans;
    }
};