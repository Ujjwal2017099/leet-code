class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        
        for(int i=0;i<s.size();i++){
            m1[s[i]]=i;
            m2[t[i]]=i;
        }
        int ans=0;
        auto x=m1.begin();
        auto y=m2.begin();
        for(int i=0;i<m1.size();i++){
            ans+=abs(y->second-x->second);
            y++;
            x++;
        }
        
        return ans;
    }
};