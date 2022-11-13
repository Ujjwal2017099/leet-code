class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        bool f=0;
        int prev=0;
        // cout<<s<<endl;
        if(s.back()!=' ') s+=' ';
        for(int i=0;i<s.length();i++){
            while(!f && i<s.length() && s[i]==' '){i++;}
            if(i==s.length()) break;
            if(f==0) prev=i;
            f=1;
            if(s[i]==' ') {fun(s,prev,i);f=0;}
        }
        
        string ans="";
        f=0;
        for(int i=0;i<s.length();i++){
            while(!f && i<s.length() && s[i]==' '){i++;}
            if(i==s.length()) break;
            f=1;
            if(s[i]==' ') f=0;
            ans += s[i];
        }
        
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]==' '){
                fun(ans,i+1,ans.length());
                break;
            }
        }
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]!=' ') break;
            ans.pop_back();
        }
        return ans;
    }
    void fun(string& s,int i,int j){
        reverse(s.begin()+i,s.begin()+j);
        // cout<<i<<" "<<j<<endl;
    }
};