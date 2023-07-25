class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        if(a.size()==3) return 1;
        int l=1,r=a.size()-2;
        while(l<=r){
            int md=(l+r)/2;
            if(a[md]>a[md-1] && a[md]>a[md+1]) return md;
            
            if(a[md]>a[md-1] && a[md]<a[md+1]) l=md+1;
            else r=md-1;
        }
        return 1;
    }
};