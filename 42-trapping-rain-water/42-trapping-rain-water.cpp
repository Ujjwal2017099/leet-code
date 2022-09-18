class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> l(h.size());l[0] = h[0];
        vector<int> r(h.size());r.back() = h.back();
        for(int i=1;i<h.size();i++){
            l[i] = max(l[i-1],h[i]);
        }
        for(int i=h.size()-2;i>=0;i--){
            r[i] = max(r[i+1],h[i]);
        }
        
        int ans = 0;
        for(int i=0;i<h.size();i++){
            ans += min(l[i],r[i]) - h[i];
        }
        return ans;
    }
};