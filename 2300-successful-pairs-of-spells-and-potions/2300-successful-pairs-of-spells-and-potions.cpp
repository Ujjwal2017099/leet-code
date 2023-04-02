class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long k) {
        int n=s.size();
        vector<int> ans(n,0);
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++){
            vector<int>::iterator it = lower_bound(p.begin(),p.end(),(k+s[i]-1)/s[i]);
            int x= it-p.begin();
            ans[i] = p.size()-x;
        }
        return ans;
    }
};