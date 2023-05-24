class Solution {
public:
    int search(vector<int>& n, int t) {
        int l=0,r=n.size()-1;
        while(l<r){
            int md=(l+r)/2;
            if(n[md] > n.back()){
                l=md+1;
            }else{
                r=md;
            }
        }
        int k=l,x=l+n.size();
        // cout<<k<<" "<<x;
        while(k<=x){
            int md=(k+x)/2;
            // cout<<md%n.size()<<" ";
            if(n[md%n.size()]>t){
                x=md-1;
            }else if(n[md%n.size()]<t){
                k=md+1;
            }else{
                return md%n.size();
            }
        }
        return -1;
    }
};