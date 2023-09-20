class Solution {
public:
    int minOperations(vector<int>& n, int x) {
        vector<int> t(n.size());
        partial_sum(n.begin(),n.end(),t.begin());
        
        for(int i=n.size()-2;i>=0;i--) n[i]+=n[i+1];
        reverse(n.begin(),n.end());
        
        // for(int i:t) cout<<i<<" ";
        // cout<<endl;
        // for(int i:n) cout<<i<<" ";
        // cout<<endl;
        int cnt=1e9;
        for(int i=0;i<t.size();i++){
            int a = x-t[i];
            if(a==0){
                cnt = min(cnt,i+1);
                // cout<<i+1<<endl;
            }
            auto it = lower_bound(n.begin(),n.end(),a);
            if(it != n.end()){
                int j = it-n.begin();
                if(a==n[j] && i+j<n.size()){
                    cnt = min(i+j+2,cnt);
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        for(int i=0;i<t.size();i++){
            int a = x-n[i];
            if(a==0){
                cnt = min(cnt,i+1);
                // cout<<i+1<<endl;
            }
            auto it = lower_bound(t.begin(),t.end(),a);
            if(it != t.end()){
                int j = it-t.begin();
                if(a==n[j] && i+j<n.size()){
                    cnt = min(i+j+2,cnt);
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return cnt>n.size() ? -1 : cnt;
    }
    
};