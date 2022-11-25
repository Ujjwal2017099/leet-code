class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        int mod=1e9+7;
        stack<vector<int>> ls;
        stack<vector<int>> rs;
        
        vector<int> l(n);
        vector<int> r(n);
        
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!ls.empty() && ls.top()[0]>=arr[i]){
                cnt += ls.top()[1];
                ls.pop();
            }
            ls.push({arr[i],cnt});
            l[i] = cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!rs.empty() && rs.top()[0]>arr[i]){
                cnt += rs.top()[1];
                rs.pop();
            }
            rs.push({arr[i],cnt});
            r[i] = cnt;
        }
        
        for(int i=0;i<n;i++){
            long long x = l[i];
            long long y = r[i];
            long long z = arr[i];
            ans = (ans + x*y*z)%mod;
        }
        return ans;
    }
};