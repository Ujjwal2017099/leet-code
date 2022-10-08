class Solution {
public:
    int threeSumClosest(vector<int>& n, int t) {
        sort(n.begin(),n.end());
        long long ans = INT_MAX;
        for(int i=0;i<n.size();i++){
            int l=0,r=n.size()-1;
            while(l<r){
                if(l==i) l++;
                if(r==i) r--;
                if(l>=r) break;
                long long sum = n[l]+n[r]+n[i];
                if(abs(sum-t) < abs(ans-t)){
                    ans = sum;
                }
                
                if(sum>t){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};