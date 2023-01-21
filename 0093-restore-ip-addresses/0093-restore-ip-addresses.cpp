class Solution {
public:
    string d;
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        d = ".";
        fun(s,0,0,0);
        return ans;
    }
    void fun(string s,int i,int l,int cnt){
        if(i>=s.size()){
            if(cnt>3 || cnt<3) return;
            string x = s.substr(l,s.size()-l);
            if(x.size()>3 || (x[0]=='0' && x.size()>1)) return;
            // cout<<"-"<<x<<"-"<<endl;
            if(x.empty()) return;
            if(stoi(x)>=0 && stoi(x)<=255) ans.push_back(s);
            return;
        }
        
        fun(s,i+1,l,cnt);
        string x = s.substr(l,i-l+1);
        if(x.size()>3 || (x[0]=='0' && x.size()>1)) return;
        if(stoi(x)>255) return;
        s.insert(i+1,d);
        fun(s,i+2,i+2,cnt+1);
    }
};