class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> m;
        int l = s.size();
        for(int i=0;i<=l-k;i++){
            string nn = s.substr(i,k);
            m.insert(nn);
            // cout<<i<<" ";
        }
        // cout<<m.size();
        return m.size()==(1<<k);
    }
};