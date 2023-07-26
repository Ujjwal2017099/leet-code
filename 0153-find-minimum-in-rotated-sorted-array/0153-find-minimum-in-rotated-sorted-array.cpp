class Solution {
public:
    int findMin(vector<int>& n) {
        if(n.size()==1 || n[0]<n.back()) return n[0];
        if(n.back()<n[0] && n[n.size()-2]>n.back()) return n.back();
        
        int l=1,r=n.size()-2;
        while(l<=r){
            int md=(l+r)/2;
            
            if(n[md]<n[md-1]) return n[md];
            if(n[l]<n[l-1]) return n[l];
            if(n[r]<n[r-1]) return n[r];
            
            if(n[md]>n[l]) l=md+1;
            else r=md-1;
        }
        return n[0];
    }
};