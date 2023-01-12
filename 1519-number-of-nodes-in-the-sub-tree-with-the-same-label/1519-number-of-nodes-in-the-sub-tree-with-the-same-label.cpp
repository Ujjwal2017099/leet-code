class Solution {
public:
    vector<int> ans;
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string& l) {
        ans.resize(n,0);
        vector<vector<int>> g(n);
        for(auto it:e){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> cnt(26,0);
        fun(g,0,-1,l,cnt);
        return ans;
    }
    vector<int> fun(vector<vector<int>>& g,int i,int par,string& l,vector<int>& cnt){
        ans[i]++;
        cnt[l[i]-'a']++;
        // cout<<i<<" ";
        if(g[i].size()==1 && g[i][0] == par){
            return cnt;
            // return;
            // return cnt;
        }
        for(int x:g[i]){
            vector<int> f(26,0);
            if(x!=par){
                vector<int> a = fun(g,x,i,l,f);
                ans[i] += a[l[i]-'a'];
                for(int i=0;i<26;i++){
                    cnt[i] += a[i];
                }
            }
        }
        // ans[i] += f[l[i]-'a'];
        // for(int i=0;i<26;i++)
        return cnt;
    }
};