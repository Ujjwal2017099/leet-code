class Solution {
public:
    vector<int> dp;
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(),d.end());
        dp.resize(s.size(),-1);
        return fun(s,0,st);
    }
    int fun(string& s,int i,unordered_set<string>& st){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++){
            string t=s.substr(i,j-i+1);
            if(st.count(t)){
                ans=min(ans,fun(s,j+1,st));
            }else{
                ans=min(ans,fun(s,j+1,st)+j-i+1);
            }
        }
        return dp[i] = ans;
    }
};