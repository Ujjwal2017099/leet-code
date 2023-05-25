class Solution {
public:
    vector<vector<int>> dp;
    int numDecodings(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        int a= fun(s,0,0);
        return a==-1?0:a;
    }
    int fun(string& s,int i,int p){
        if(i==s.size()){
            if(p==i) return 0;
            // if( p != i || s[p]=='0' || stoi(s.substr(p,i-p)) > 26 ) return 0;
            // cout<<i<<" "<<p<<endl;
            return 1;
        }
        if(s[p]=='0'){
            return 0;
        }
        int a=stoi(s.substr(p,i-p+1));
        // cout<<a<<" "<<i<<" "<<p<<endl;
        if(a>26){
            return 0;
        }
        
        if(dp[i][p]!=-1) return dp[i][p];
        int x = fun(s,i+1,p);
        int y = fun(s,i+1,i+1);
        // cout<<i<<" "<<p<<" "<<x<<" "<<y<<endl;
        return dp[i][p] = x+y;
    }
};