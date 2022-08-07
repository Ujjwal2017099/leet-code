class Solution {
    map<pair<int,char>,int> dp;
    map<pair<int,char>,bool> m;
    map<char,vector<char>> g;
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        g[' '] = {'a','e','i','o','u'};
        g['a'] = {'e'};
        g['e'] = {'a','i'};
        g['i'] = {'a','e','o','u'};
        g['o'] = {'i','u'};
        g['u'] = {'a'};
        return fun(n,' ');
    }
    int fun(int n,char last){
        int cnt=0;
        if(n==0){
            return 1;
        }
        if(m[{n,last}]){
            return dp[{n,last}];
        }
        for(int i=0 ; i<g[last].size() ; i++){
            cnt = (cnt + fun(n-1,g[last][i]))%mod;
        }
        
        m[{n,last}] = 1;
        dp[{n,last}]=cnt;
        return cnt;
    }
};