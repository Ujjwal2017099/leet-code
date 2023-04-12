class Solution {
public:
    string simplifyPath(string p) {
        string ans="/";
        
        for(int i=1;i<p.size();i++){
            int d=0;
            while(i<p.size() && p[i]=='.'){d++;i++;}
            if(d) {
                if((i<p.size() && p[i]!='/') || ans.back()!='/'){
                    while(d--) ans += '.';
                }
                if(d==2 and ans.back()=='/'){
                    ans.pop_back();
                    while(ans.size() && ans.back()!='/') ans.pop_back();
                    if(ans.empty()) ans += '/';
                }
                if(d>2){
                    while(d--){   
                        ans += '.';
                    }
                }
                i--;
            }
            else if(p[i]=='/' && ans.back()!='/') ans+='/';
            else if(p[i]!='/') ans+=p[i];
        }
        if(ans.size()>1 && ans.back()=='/') ans.pop_back(); 
        return ans;
    }
};