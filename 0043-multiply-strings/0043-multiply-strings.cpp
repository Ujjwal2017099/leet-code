class Solution {
public:
    string multiply(string n1, string n2) {
        string ans="";
        int cnt=0;
        while(!n1.empty() && n1.back()=='0'){
            cnt++;
            n1.pop_back();
        }
        while(!n2.empty() && n2.back()=='0'){
            cnt++;
            n2.pop_back();
        }
        if(n1.empty() || n2.empty()) return "0";
        vector<string> m;
        for(int i=n2.size()-1;i>=0;i--){
            string t = "";
            int c=0;
            for(int j=n1.size()-1;j>=0;j--){
                int temp = (n2[i]-'0')*(n1[j]-'0')+c;
                char x = temp%10 + '0';
                t = x + t;
                c = temp/10;
            }
            while(c>0){
                char x = c%10+'0';
                t = x + t;
                c/=10;
            }
            int sh = n2.size()-i-1;
            while(sh--){
                t += '0';
            }
            m.push_back(t);
        }
        int mx=0;
        for(string s:m){
            mx = max(mx,(int)s.length());
        }
        // cout<<mx<<endl;
        for(string& s:m){
            while(mx-s.length()){
                s='0'+s;
            }
            // cout<<mx-s.length()<<endl;
        }
        int car=0;
        for(int j=m[0].size()-1;j>=0;j--){
            int sm=0;
            for(int i=0;i<m.size();i++){
                sm += m[i][j]-'0';
            }
            sm+=car;
            char c = sm%10+'0';
            ans = c+ans;
            car = sm/10;
        }
        while(car>0){
            char x = car%10+'0';
            ans = x+ans;
            car/=10;
        }
        if(ans.empty()) return "0";
        while(cnt--) ans+='0';
        return ans;
    }
};