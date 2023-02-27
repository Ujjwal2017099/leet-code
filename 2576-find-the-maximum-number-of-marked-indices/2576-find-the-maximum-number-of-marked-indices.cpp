class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        map<int,bool> m;
        int prev=0;
        int cnt=0;
        for(int i=0;i<(n+1)/2;i++){
            if(m[i]) continue;
            auto it=lower_bound(v.begin()+(n+1)/2,v.end(),v[i]*2);
            if(it==v.end()) break;
            
            int j=it-v.begin();
            // while(j<n && m[j]) j++;
            j=max(j,prev+1);
            if(j>=n) break;
            m[j]=1;
            m[i]=1;
            cnt++;
            prev=j;
        }
        return cnt*2;
    }
    
};