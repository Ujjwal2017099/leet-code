class Solution {
public:
    int myAtoi(string s) {
        string t="";
        bool n=0;
        bool sg=0;
        for(int i=0;i<s.length();i++){
            while(!sg && !n && s[i]==' ' && i<s.length()) i++;
            if(i<s.length() && s[i]!='-' && s[i]!='+' && !(s[i]>='0' && s[i]<='9')) break;
            if(i<s.length() && (s[i]=='+' || s[i]=='-') && !sg && !n) {t+=s[i];sg=1;}
            else if(i<s.length() && (n || sg) && !(s[i]>='0' && s[i]<='9')) break;
            else if(i<s.length() && (s[i]>='0' && s[i]<='9')){ t+=s[i];n=1;}
            // t += s[i];
        }
        cout<<t;
        if(t.size()==1 && (t[0]=='-' || t[0] == '+')){return 0;}
        if(t.empty() || !n) return 0;
        int sign = t[0]=='-'?1:0;
        while(t.front()=='0' || t.front()=='-' || t.front()=='+'){
            t.erase(t.begin());
        }
        if(t.empty()) return 0;
        
        if(sign){
            t = '-'+t;
        }
        if(t.size()>=12) {
            return t.front()=='-'?INT_MIN:INT_MAX;
        }
        long long n1 = stoll(t);
        
        return n1<INT_MIN?INT_MIN:n1>INT_MAX?INT_MAX:n1;
    }
};