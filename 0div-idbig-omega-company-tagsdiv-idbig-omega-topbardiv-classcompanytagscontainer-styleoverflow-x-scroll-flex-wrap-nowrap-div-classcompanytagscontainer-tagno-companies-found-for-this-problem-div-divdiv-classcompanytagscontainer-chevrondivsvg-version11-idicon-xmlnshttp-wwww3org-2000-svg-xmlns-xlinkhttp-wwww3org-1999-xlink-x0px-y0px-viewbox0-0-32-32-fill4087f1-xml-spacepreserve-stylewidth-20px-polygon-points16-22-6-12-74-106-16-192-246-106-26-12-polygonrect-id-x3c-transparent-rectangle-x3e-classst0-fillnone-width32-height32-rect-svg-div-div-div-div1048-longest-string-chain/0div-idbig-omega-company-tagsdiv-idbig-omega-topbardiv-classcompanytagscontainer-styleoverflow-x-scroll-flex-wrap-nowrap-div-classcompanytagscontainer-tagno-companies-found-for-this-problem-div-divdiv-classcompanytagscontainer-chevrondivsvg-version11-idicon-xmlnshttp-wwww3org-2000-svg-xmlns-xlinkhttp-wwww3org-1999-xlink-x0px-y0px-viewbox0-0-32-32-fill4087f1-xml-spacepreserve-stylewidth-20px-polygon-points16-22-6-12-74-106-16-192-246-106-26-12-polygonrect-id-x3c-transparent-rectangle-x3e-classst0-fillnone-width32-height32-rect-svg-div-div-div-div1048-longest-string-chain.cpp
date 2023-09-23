class Solution {
public:
    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),[&](string a,string b){
            return a.size()<b.size();
        });
        map<string,int> mp;
        map<int,int> vis;
        for(int i=0;i<w.size();i++){
            mp[w[i]]=i+1;
        }
        int ans = 1;
        
        for(int i=w.size()-1;i>0;i--){ 
            if(vis[i]) continue;
            ans=max(ans,fun(mp,vis,w,i));
        }
        
        return ans;
    }
    int fun(map<string,int>& mp,map<int,int>& vis,vector<string>& w,int x){
        
        if(vis[x]) return vis[x];
        int cnt=1;
        // string s = w[x];
        // vis[x]=1;
        for(int i=0;i<w[x].size();i++){
            string y = w[x].substr(0,i-0) + w[x].substr(i+1,w[x].size()-i-1);
            // cout<<x<<" ";
            if(mp[y]){
                cnt = max(cnt,fun(mp,vis,w,mp[y]-1)+1);
            }
        }
        // cout<<endl;
        return vis[x] = cnt;
    }
};