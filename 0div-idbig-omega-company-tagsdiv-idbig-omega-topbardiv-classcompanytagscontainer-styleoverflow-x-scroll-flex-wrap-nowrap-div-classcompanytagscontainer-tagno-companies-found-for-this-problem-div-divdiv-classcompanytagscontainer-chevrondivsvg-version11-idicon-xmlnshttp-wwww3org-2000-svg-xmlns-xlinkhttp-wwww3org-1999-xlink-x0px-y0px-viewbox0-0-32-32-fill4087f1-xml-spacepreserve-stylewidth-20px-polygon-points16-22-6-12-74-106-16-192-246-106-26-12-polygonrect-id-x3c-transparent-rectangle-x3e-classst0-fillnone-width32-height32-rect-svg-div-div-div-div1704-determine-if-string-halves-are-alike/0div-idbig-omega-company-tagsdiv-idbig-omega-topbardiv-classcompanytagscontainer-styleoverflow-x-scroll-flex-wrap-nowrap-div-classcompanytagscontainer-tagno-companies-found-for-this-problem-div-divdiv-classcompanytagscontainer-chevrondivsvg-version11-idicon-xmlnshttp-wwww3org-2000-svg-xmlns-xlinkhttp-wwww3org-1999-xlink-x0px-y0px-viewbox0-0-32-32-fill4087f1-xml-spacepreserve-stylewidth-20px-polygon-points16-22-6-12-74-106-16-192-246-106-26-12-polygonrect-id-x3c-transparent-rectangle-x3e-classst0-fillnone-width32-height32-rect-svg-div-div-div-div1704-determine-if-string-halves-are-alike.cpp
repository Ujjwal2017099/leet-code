class Solution {
public:
    bool halvesAreAlike(string s) {
        string v = "aeiouAEIOU";
        map<int,bool> mp;
        for(char c:v) mp[c] = 1;
        int n = s.length()/2;
        int cnt1 = 0,cnt2 = 0;
        for(int i=0;i<n;i++) if(mp[s[i]]){ cnt1++;}
        for(int i=n;i<2*n;i++) mp[s[i]] ? cnt2++ : cnt2;
       // cout<<cnt1<<" "<<cnt2<<" "<<n;
        return cnt1==cnt2;
    }
};