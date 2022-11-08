class Solution {
public:
    string makeGood(string s) {
        string t="";
        for(char c:s){
            if(t.empty()){
                t+=c;
            }else{
                if(isbad(t.back(),c)){
                    t.pop_back();
                }else{
                    t+=c;
                }
            }
        }
        return t;
    }
    bool isbad(char a,char b){
        char x = max(a,b);
        b = min(a,b);
        a = x;

        if(a>='a' && a <= 'z' && b>='A' && b<='Z'){
            if(a==b+32) return 1;
        }

        return 0;
    }
};