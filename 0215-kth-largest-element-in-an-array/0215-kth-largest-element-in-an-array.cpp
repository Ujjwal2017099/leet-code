class Solution {
public:
    int findKthLargest(vector<int>& n, int k) {
        sort(n.begin(),n.end());
        return n[n.size()-k];
    }
};