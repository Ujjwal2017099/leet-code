class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++){
            int x=s[i],y=s[i-1];
            ans += abs(x-y);
        }
        return ans;
    }
};