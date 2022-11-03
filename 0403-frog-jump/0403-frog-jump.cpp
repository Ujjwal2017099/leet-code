class Solution {
public:
    unordered_map<int,bool> mp;
    map<pair<int,int>,bool> dp;
    map<pair<int,int>,bool> vis;
    bool canCross(vector<int>& s) {
        for(int i:s){
            mp[i]=1;
        }
        if(s[1]-s[0]!=1) return 0;
        return fun(1,s[1],s.back(),s[0]);
    }
    bool fun(int x,int pos,int n,int prev){
        if(x<0 || pos>n || !mp[pos] || pos==prev){
            return 0;
        }
        if(pos==n){
            return 1;
        }
        if(vis[{x,pos}]) return dp[{x,pos}];
        vis[{x,pos}]=1;
        return dp[{x,pos}] = fun(x,pos+x,n,pos)|fun(x-1,pos+x-1,n,pos)|fun(x+1,pos+x+1,n,pos);
    }
};