class Solution {
public:
    bool detectCapitalUse(string w) {
        bool f = (w[0]>='A' && w[0]<='Z');
        int cnt=0;
        for(char c:w){
            if(c>='A' && c<='Z') cnt++;
        }
        if(cnt==w.size()) return 1;
        if(cnt==1 && f) return 1;
        if(cnt==0) return 1;
        
        return 0;
    }
};