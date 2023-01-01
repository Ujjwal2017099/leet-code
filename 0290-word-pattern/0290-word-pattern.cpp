class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string> mp;
        map<string,char> mx;
        int prev=0;
        s += ' ';
        int cnt=0;
        for(char c:p){
            cnt++;
            for(int i=prev;i<s.length();i++){
                if(s[i]==' '){
                    string t = s.substr(prev,i-prev);
                    if(mp.find(c)==mp.end() and mx.find(t)==mx.end()){
                        mp[c] = t;
                        mx[t] = c;
                    }
                    else if(mp[c]!=t || mx[t]!=c){
                        return 0;
                    }
                    prev = i+1;
                    break;
                }
            }
            if(prev==s.length()) break;
        }
        if(prev<s.length() || cnt<p.length()) return 0;
        return 1;
    }
};