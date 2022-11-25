class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<vector<int>> ls;
        stack<vector<int>> rs;
        
        vector<int> l(n);
        vector<int> r(n);
        
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!ls.empty() && ls.top()[0] >= h[i]){
                cnt += ls.top()[1];
                ls.pop();
            }
            ls.push({h[i],cnt});
            l[i] = cnt;
        }
        
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!rs.empty() && rs.top()[0] >= h[i]){
                cnt += rs.top()[1];
                rs.pop();
            }
            rs.push({h[i],cnt});
            r[i] = cnt;
        }
        int ans = h[0];
        // for(int i:l) cout<<i<<" ";
        // cout<<endl;
        // for(int i:r) cout<<i<<" ";
        for(int i=0;i<n;i++){
            int t = (l[i]+r[i]-1)*h[i];
            ans = max(ans,t);
        }
        return ans;
    }
};