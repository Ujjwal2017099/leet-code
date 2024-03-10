class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        sort(c.begin(),c.end(),greater<int>());
        int sm=0;
        for(int i:a) sm+=i;
        int ans=0;
        for(int i=0;i<c.size();i++){
            if(sm<=0) break;
            ans++;
            sm-=c[i];
        }
        return ans;
    }
};