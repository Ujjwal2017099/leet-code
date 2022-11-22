class Solution {
public:
    int minimumDeviation(vector<int>& n) {
        int ans=INT_MAX;
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<n.size();i++){
            if(n[i]&1) n[i] *= 2;
            mx=max(mx,n[i]);
            mn=min(mn,n[i]);
        }
        ans = mx-mn;
        priority_queue<int> pq;
        for(int i:n) pq.push(i);
        
        while(!(pq.top()&1)){
            int x=pq.top();pq.pop();
            x/=2;
            mn = min(mn,x);
            pq.push(x);
            ans = min(ans,pq.top()-mn);
        }
        // ans=pq.top()-mn;
        return ans;
    }
};