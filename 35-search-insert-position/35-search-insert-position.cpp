class Solution {
public:
    int searchInsert(vector<int>& n, int t) {
        int l=0,r=n.size()-1;
        if(n[r] < t) return r+1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(n[mid]==t) return mid;
            if(n[mid] > t){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
    }
};