class Solution {
public:
    int ans;
    int longestPath(vector<int>& p, string& s) {
        // if(p.size()==1) return 1;
        vector<vector<int>> g(s.size());
        for(int i=1;i<p.size();i++){
            g[p[i]].push_back(i);
            g[i].push_back(p[i]);
        }
        ans=1;
        fun(g,s,0,-1);
        return ans;
    }
    int fun(vector<vector<int>>& g,string& s,int i,int par){
        if(g[i].size()==1 && g[i][0]==par){
            return 1;
        }
        int a = 1;
        priority_queue<int> b;
        for(int x:g[i]){
            if(x!=par && s[i]!=s[x]){
                int it = fun(g,s,x,i)+1;
                // if(s[i]!=s[x]) it++;
                a = max(a,it);
                b.push(it);
                ans = max(ans,it);
            }
            else if(x!=par && s[i]==s[x]){
                int it = fun(g,s,x,i);
                // a = max(a,it);
                ans = max(ans,it);
            }
        }
        if(b.size()>=2){
            int sm = b.top();
            b.pop();
            sm += b.top();
            ans = max(ans,sm-1);
        }
        return a;
    }
};