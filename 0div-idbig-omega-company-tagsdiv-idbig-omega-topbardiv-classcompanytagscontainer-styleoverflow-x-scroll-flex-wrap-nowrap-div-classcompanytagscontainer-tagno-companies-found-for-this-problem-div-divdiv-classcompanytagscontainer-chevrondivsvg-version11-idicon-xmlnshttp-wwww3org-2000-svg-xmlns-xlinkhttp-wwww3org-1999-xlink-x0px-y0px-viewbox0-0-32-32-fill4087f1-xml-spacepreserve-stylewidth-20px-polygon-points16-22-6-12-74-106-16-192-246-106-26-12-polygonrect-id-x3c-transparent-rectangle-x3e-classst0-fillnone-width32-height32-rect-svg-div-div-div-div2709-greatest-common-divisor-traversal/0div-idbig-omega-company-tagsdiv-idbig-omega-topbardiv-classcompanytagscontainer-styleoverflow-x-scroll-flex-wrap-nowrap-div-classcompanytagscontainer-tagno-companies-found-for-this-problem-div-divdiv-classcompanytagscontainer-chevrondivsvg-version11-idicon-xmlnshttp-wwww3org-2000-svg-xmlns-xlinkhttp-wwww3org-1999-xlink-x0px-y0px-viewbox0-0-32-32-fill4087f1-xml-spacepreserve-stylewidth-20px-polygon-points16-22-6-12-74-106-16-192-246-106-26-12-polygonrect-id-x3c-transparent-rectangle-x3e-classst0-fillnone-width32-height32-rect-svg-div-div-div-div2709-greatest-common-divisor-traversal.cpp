class Solution {
public:
    vector<int> par;
    bool canTraverseAllPairs(vector<int>& t) {
        if(t.size()==1) return 1;
        set<int> s(t.begin(),t.end());
        if(*s.begin()==1) return 0;
        vector<int> n(s.begin(),s.end());
        par.resize(n.size(),-1);
        int mx=n[0];
        for(int i=1;i<n.size();i++){
            mx=max(mx,n[i]);
        }
        vector<int> pr(mx+1,-0);
        vector<int> v;
        for(int i=2;i<=mx;i++){
            if(pr[i]) continue;
            v.push_back(i);
            for(int j=i*2;j<=mx;j+=i){
                pr[j]=1;
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n.size();i++){
            for(int j:v){
                if(n[i]%j==0){
                    mp[j].push_back(i);
                }
            }
        }
        
        for(auto it:mp){
            for(int i=0;i<it.second.size()-1;i++){
                int x=it.second[i],y=it.second[i+1];
                Union(x,y);
            }
        }
        int cnt=0;
        for(int i:par){
            if(i<0) cnt++;
        }
        
        return cnt==1;
    }
    void Union(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y) return;
        if(par[x]<par[y]){
            par[x]+=par[y];
            par[y]=x;
        }else{
            par[y]+=par[x];
            par[x]=y;
        }
    }
    int find(int a){
        if(par[a]<0) return a;
        return par[a]=find(par[a]);
    }
};