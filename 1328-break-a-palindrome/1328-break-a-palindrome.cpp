class Solution {
public:
    string breakPalindrome(string p) {
        if(p.length()==1){
            return "";
        }
        bool ok=0;
        for(int i=0;i<p.length();i++){
            if(p.length()&1 and i==p.length()/2) continue;
            if(p[i]!='a'){
                p[i]='a';
                ok=1;break;
            }
        }
        if(ok){
            return p;
        }
        
        p.back() = 'b';
        return p;
    }
};