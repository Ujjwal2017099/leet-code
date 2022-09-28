class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int fact = 1;
        int nxt = 0;
        for(int i=d.size()-1;i>=0;i--){
            d[i] += fact;
            fact = d[i]/10;
            d[i] %= 10;
            if(i==0) nxt = fact;
        }
        vector<int> ans;
        if(nxt){
            ans.resize(d.size()+1);
            ans[0] = nxt;
            for(int i=1;i<=d.size();i++){
                ans[i] = d[i-1];
            }
            return ans;
        }
        return d;
    }
};