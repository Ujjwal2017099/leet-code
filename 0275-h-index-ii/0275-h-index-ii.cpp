class Solution {
public:
    int hIndex(vector<int>& c) {
        int ans=0;
        for(int i=1;i<=c.back();i++){
            auto it=lower_bound(c.begin(),c.end(),i);
            if(it==c.end()) break;
            int x=it-c.begin();
            if(c.size()-x>=i) ans=i;
            else break;
        }
        return ans;
    }
};