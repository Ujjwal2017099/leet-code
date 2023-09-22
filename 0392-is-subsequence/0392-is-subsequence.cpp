class Solution {
public:
    bool isSubsequence(string s, string t) {
        int prev=0;
        for(int i=0;i<s.size();i++){
            bool f=0;
            for(int j=prev;j<t.size();j++){
                if(t[j]==s[i]){
                    f=1;
                    prev=j+1;
                    break;
                }
            }
            if(!f) return 0;
        }
        return 1;
    }
};