class Solution {
public:
    int search(vector<int>& n, int t) {
        int l=0,r=n.size()-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(t==n[mid]) return mid;
            if(t>n[mid]) l=mid+1;
            if(t<n[mid]) r=mid-1;
        }
        
        return -1;
    }
};