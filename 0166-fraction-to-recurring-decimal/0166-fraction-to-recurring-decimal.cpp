class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        if(n==0) return "0";
        int cnt=0;
        if(n<0) cnt++;
        if(d<0) cnt++;
        map<long long,long long> m;
        string ans="";
        if(cnt&1) ans.push_back('-');
        n=abs(n);
        d=abs(d);
        long long x = n/d;
        // cout<<ans;
        ans += to_string(x);
        n%=d;
        
        bool f=0;
        if(n){    
            ans.push_back('.');
            f=1;
            n*=10;
        }
        while(n){
            if(m[n]){
                return insert_at(m[n],ans);
            }
            
            if(!(n/d)) {
                if(f){ans.push_back('0');}
                n*=10;
                f=1;
            }
            else {m[n]=ans.size(); ans += to_string(n/d);n%=d;f=0;}
        }
        
        return ans;
    }
    string insert_at(int x,string& t){
        string ans="";
        for(int i=0;i<t.size();i++){
            if(ans.size()==x){
                ans.push_back('(');
            }
            ans.push_back(t[i]);
        }
        ans.push_back(')');
        return ans;
    }
};