class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(char c:s) m[c]++;
        int mx=0;
        int ans=0;
        for(auto it:m){
            if(it.second&1) mx=1;
            ans+=(it.second/2)*2;
        }
        ans+=mx;
        return ans;
    }
};