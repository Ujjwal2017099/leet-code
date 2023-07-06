class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        if(n.empty()) return {-1,-1};
        vector<int>::iterator l = upper_bound(n.begin(),n.end(),t);
        vector<int>::iterator f = lower_bound(n.begin(),n.end(),t);
        int x = static_cast<int>(f-n.begin());
        // cout<<x;
        if(f==n.end() || n[x]!=t) return {-1,-1};
        return {x , static_cast<int>(l-n.begin())-1};
    }
};